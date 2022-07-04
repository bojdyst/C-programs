#include <stdio.h>

int main(void){
    int t1[10];
    double t2[10];
    int *pointer1;
    double *pointer2;
    printf("Enter 10 elements to fill first array:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &t1[i]);
    }
    printf("First array:\n");
    for (int p = 0; p < 10; p++) {
        printf("%d\t", t1[p]);
        printf("%d\n", &t1[p]);
    }
    printf("\n");
    printf("Enter 10 elements to fill second array:\n");
    for(int j = 0; j < 10; j++){
        scanf("%lf", &t2[j]);
    }
    printf("Second array:\n");
    for (int m = 0; m < 10; m++) {
        printf("%lf\t", t2[m]);
        printf("%d\n", &t2[m]);
    }

    pointer1 = &t1[0];
    pointer2 = &t2[0];

    printf("\n");
    printf("First array using pointers:\n");

    for(int q = 0; q < 10; q++){
        printf("%d\t", *(pointer1 + q));
        printf("%d\n", (pointer1 + q));
    }
    printf("\n");
    printf("Second array using pointers:\n");

    for(int y = 0; y < 10; y++){
        printf("%lf\t", *(pointer2 + y));
        printf("%d\n", (pointer2 + y));
    }
    return 0;
}


