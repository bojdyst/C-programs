#include <stdio.h>

int main(void) {
    int n, k, tmp, sum = 0;
    printf("Enter the n number:\n");
    scanf("%d", &n);
    printf("Enter the k number:\n");
    scanf("%d", &k);
    int tab[n][n];
    for (int t = 0; t < n; t++) {
        for (int m = 0; m < n; m++) {
            tab[t][m] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Insert %d numbers to [%d] row (separated with spacebar)\n", n, i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &tab[i][j]);
        }
    }
    printf("\n");

    for(int r = 1; r <= ((n/2) + 1); r++){
        for (int i = r; i < (n - r); i++) {
            for (int j = r; j < (n - r); j++) {
                tmp = 0;
                for (int x = i - r; x <= i + r; x++) {
                    for (int y = j - r; y <= j + r; y++) {
                        if (x == i - r || x == i + r || y == j - r || y == j + r) {
                            tmp += tab[x][y];
                        }
                    }
                }
                if (tmp == k) {
                    printf("The centre is: [%d][%d]\n", i, j);
                    sum += 1;
                }
            }
        }
    }
    printf("There's a following number of such squares: %d\n", sum);
    return 0;
}


