#include <stdio.h>

int main(void) {
    int n;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int t[n][n];
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;
    int direction = 1;
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = 0;
        }
    }
    printf("\n");
    while (k <= (n * n)) {
        if (direction == 1) {
            for (int i = left; i <= right; i++) {
                t[top][i] = k;
                k++;
            }
            top += 1;
            direction = 2;
        }
        if (direction == 2) {
            for (int i = top; i <= bottom; i++) {
                t[i][right] = k;
                k++;
            }
            right -= 1;
            direction = 3;
        }
        if (direction == 3) {
            for (int i = right; i >= left; i--) {
                t[bottom][i] = k;
                k++;
            }
            bottom -= 1;
            direction = 4;
        }
        if (direction == 4) {
            for (int i = bottom; i >= top; i--) {
                t[i][left] = k;
                k++;
            }
            left += 1;
            direction = 1;
        }
    }

    printf("Spiral matrix:\n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
return 0;
}



