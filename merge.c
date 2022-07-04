#include <stdio.h>
#include <stdlib.h>

void sorting_arrays(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}


int merge(int t1[], int N1, int t2[], int N2, int t3[]) {
    int i = 0;
    int j = 0;
    int m = 0;
    while(i < N1 && j < N2) {
        if (t1[i] <= t2[j]) {
            t3[m] = t1[i];
            i++;
        }
        else if (t1[i] > t2[j]) {
            t3[m] = t2[j];
            j++;
        }
        m++;
    }
    while (i < N1) {
        t3[m] = t1[i];
        i++;
        m++;
    }
    while (j < N2) {
        t3[m] = t2[j];
        j++;
        m++;
    }

    printf("Sorted array of both:\n");
    int k = 0;
    for(int i = 0; i < (N1+N2); i++){
        if (t3[i] != t3[i + 1]){
            printf("%d ", t3[i]);
            k++;
        }
    }
    printf("\n");
    printf("Length of result array:\n");
    printf("%d\n", k);
}


int main() {
    int N1, N2;
    printf("Enter length of the first array:");
    scanf("%d", &N1);
    printf("Enter length of the second array:");
    scanf("%d", &N2);
    int t1[N1];
    int t2[N2];
    int t3[N1+N2];
    printf("\n");
    for (int i = 0; i <= N1; i++){
        t1[i] = rand() % 10;
    }
    for (int j = 0; j <= N2; j++){
        t2[j] = rand() % 10;
    }
    sorting_arrays(t1, N1);
    sorting_arrays(t2, N2);
    printf("First sorted array:\n");
    for (int p = 0; p < N1; p++) {
        printf("%d ", t1[p]);
    }
    printf("\n");
    printf("Second sorted array:\n");
    for (int m = 0; m < N2; m++) {
        printf("%d ", t2[m]);
    }
    printf("\n");
    merge(t1, N1, t2, N2, t3);
    return 0;
}


