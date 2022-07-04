#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 64

typedef struct Vector {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;

typedef struct Person {
    int age;
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
} Person;

// Allocate vector to initial capacity (block_size elements),
// Set element_size, size (to 0), capacity
void init_vector(Vector *vector, size_t block_size, size_t element_size) {
    vector->element_size = element_size;
    vector->size = 0;
    vector->capacity = block_size;
    vector->data = malloc(block_size * element_size);
}

// If new_capacity is greater than the current capacity,
// new storage is allocated, otherwise the function does nothing.
void reserve(Vector *vector, size_t new_capacity) {
    if (new_capacity <= vector->capacity) return;
    vector->capacity = new_capacity;
    void *newData = malloc(new_capacity * vector->element_size);
    memcpy(newData, vector->data, vector->size * vector->element_size);

    free(vector->data);
    vector->data = newData;
}

// Resizes the vector to contain new_size elements.
// If the current size is greater than new_size, the container is
// reduced to its first new_size elements.

// If the current size is less than new_size,
// additional zero-initialized elements are appended
void resize(Vector *vector, size_t new_size) {
    if (new_size < vector->size) {
        vector->size = new_size;
    } else if (new_size > vector->size) {
        reserve(vector, new_size);
        memset((char *) vector->data + (vector->size * vector->element_size), 0, (new_size - vector->size) * vector->element_size);
        vector->size = new_size;
    }
}

// Add element to the end of the vector
void push_back(Vector *vector, void *value) {
    if (vector->size == vector->capacity)
        reserve(vector, vector->capacity * 2);

    char *dest = (char *) vector->data + vector->size * vector->element_size;
    memcpy((void *) dest, value, vector->element_size);
    vector->size++;
}

// Remove all elements from the vector
void clear(Vector *vector) {
    vector->size = 0;
}

// Remove the last element from the vector
void pop_back(Vector *vector) {
    if (vector->size != 0)
        vector->size--;
}

// Insert new element at index (0 <= index <= size) position
void insert(Vector *vector, int index, void *value) {
    if (index < 0 || index > vector->size) return;
    if (index == vector->size) {
        push_back(vector, value);
        return;
    }

    if (vector->size == vector->capacity)
        reserve(vector, vector->capacity * 2);

    push_back(vector, value);
    push_back(vector, value);

    for(int i = vector->size-2; i > index;i--)
        memmove((char *) vector->data + (i) * vector->element_size,
                (char *) vector->data + (i - 1) * vector->element_size,
                vector->element_size);

    memmove((char *) vector->data + index * vector->element_size,
            (char *) vector->data + (vector->size-1) * vector->element_size,
            vector->element_size);
    vector->size--;
}

// Erase element at position index
void erase(Vector *vector, int index) {
    if (index < 0 || index >= vector->size) return;
    if (index == vector->size - 1) {
        pop_back(vector);
        return;
    }

    for(int i = index; i < vector->size-1;i++)
        memmove((char *) vector->data + (i) * vector->element_size,
                (char *) vector->data + (i + 1) * vector->element_size,
                vector->element_size);

    vector->size--;
}

// Erase all elements that compare equal to value from the container
void erase_value(Vector *vector, void *value, int(*cmp)(const void *, const void *)) {
    for (int i = 0; i < vector->size; ++i) {
        char *element = (char *) vector->data + (i * vector->element_size);
        if (cmp(value, element) == 0) {
            erase(vector, i);
            i--;
        }
    }
}

// Erase all elements that satisfy the predicate from the vector
void erase_if(Vector *vector, int (*predicate)(void *)) {
    for (int i = 0; i < vector->size; ++i) {
        char *element = (char *) vector->data + i * vector->element_size;
        if (predicate(element)) {
            erase(vector, i);
            i--;
        }
    }
}

// Request the removal of unused capacity
void shrink_to_fit(Vector *vector) {
    if (vector->size == vector->capacity) return;
    vector->capacity = vector->size;
    void *newData = malloc(vector->size * vector->element_size);
    memcpy(newData, vector->data, vector->size * vector->element_size);
    free(vector->data);
    vector->data = newData;
}

// Print integer vector
void print_vector_int(Vector *vector) {
    size_t size = vector->size;
    printf("%d\n", vector->capacity);
    for (int i = 0; i < size; ++i) {
        char *element = (char *) vector->data + i * vector->element_size;
        printf("%d ", *(int *) element);
    }
}

// Print char vector
void print_vector_char(Vector *vector) {
    size_t size = vector->size;
    printf("%d\n", vector->capacity);
    for (int i = 0; i < size; ++i) {
        char *element = (char *) vector->data + i * vector->element_size;
        printf("%c ", *element);
    }
}

// Print vector of Person
void print_vector_person(Vector *vector) {
    size_t size = vector->size;
    printf("%d\n", vector->capacity);
    for (int i = 0; i < size; ++i) {
        Person *element = (Person *) ((char *) vector->data + i * vector->element_size);
        printf("%d %s %s\n", element->age, element->first_name, element->last_name);
    }
}

// integer comparator - increasing order
int int_cmp(const void *v1, const void *v2) {
    if (*(int *) v1 < *(int *) v2)
        return -1;
    if (*(int *) v1 > *(int *) v2)
        return 1;
    return 0;
}

// char comparator - lexicographical order (case sensitive)
int char_cmp(const void *v1, const void *v2) {
    if (*(char *) v1 < *(char *) v2)
        return -1;
    if (*(char *) v1 > *(char *) v2)
        return 1;
    return 0;
}

// Person comparator:
// Sort according to age (decreasing)
// When ages equal compare first name and then last name
int person_cmp(const void *p1, const void *p2) {
    Person *person1 = (Person *) p1;
    Person *person2 = (Person *) p2;

    if (person1->age < person2->age)
        return -1;
    if (person1->age > person2->age)
        return 1;

    int i = strcmp(person1->first_name, person1->first_name);
    if (i == 0)
        i = strcmp(person1->last_name, person1->last_name);
    return i;
}

// predicate: check if number is even
int is_even(void *value) {
    return *(int *) value % 2 == 0;
}

// predicate: check if char is a vowel
int is_vowel(void *value) {
    char sign = *(char *) value;
    sign = tolower(sign);
    return sign == 'a'
           || sign == 'e'
           || sign == 'i'
           || sign == 'o'
           || sign == 'u'
           || sign == 'y';
}

// predicate: check if person is older than 25
int is_older_than_25(void *person) {
    return ((Person *) person)->age > 25;
}

// -------------------------------------------------------------

void read_int(void *value) {
    scanf("%d", (int *) value);
}

void read_char(void *value) {
    char c[2];
    scanf("%s", c);
    *(char *) value = c[0];
}

void read_person(void *value) {
    Person *person = (Person *) value;
    scanf("%d %s %s", &person->age, person->first_name, person->last_name);
}

void vector_test(Vector *vector, int n, void(*read)(void *),
                 int (*cmp)(const void *, const void *), int(*predicate)(void *)) {
    char op[2];
    int index;
    size_t size;
    void *v = malloc(vector->element_size);
    for (int i = 0; i < n; ++i) {
        scanf("%s", op);
        switch (op[0]) {
            case 'p': // push_back
                read(v);
                push_back(vector, v);
                break;
            case 'i': // insert
                scanf("%d", &index);
                read(v);
                insert(vector, index, v);
                break;
            case 'e': // erase
                scanf("%d", &index);
                read(v);
                erase(vector, index);
                erase_value(vector, v, cmp);
                break;
            case 'd': // erase (predicate)
                erase_if(vector, predicate);
                break;
            case 'r': // resize
                scanf("%zu", &size);
                resize(vector, size);
                break;
            case 'c': // clear
                clear(vector);
                break;
            case 'f': // shrink
                shrink_to_fit(vector);
                break;
            case 's': // sort
                qsort(vector->data, vector->size,
                      vector->element_size, cmp);
                break;
            default:
                printf("No such operation: %s\n", op);
                break;
        }
    }
    free(v);
}

int main(void) {
    int to_do, n;
    Vector vector_int, vector_char, vector_person;
    scanf("%d%d", &to_do, &n);
    switch (to_do) {
        case 1:
            init_vector(&vector_int, 4, sizeof(int));
            vector_test(&vector_int, n, read_int, int_cmp, is_even);
            print_vector_int(&vector_int);
            free(vector_int.data);
            break;
        case 2:
            init_vector(&vector_char, 2, sizeof(char));
            vector_test(&vector_char, n, read_char, char_cmp, is_vowel);
            print_vector_char(&vector_char);
            free(vector_char.data);
            break;
        case 3:
            init_vector(&vector_person, 2, sizeof(Person));
            vector_test(&vector_person, n, read_person, person_cmp, is_older_than_25);
            print_vector_person(&vector_person);
            free(vector_person.data);
            break;
        default:
            printf("Nothing to do for %d\n", to_do);
            break;
    }
    return 0;
}
