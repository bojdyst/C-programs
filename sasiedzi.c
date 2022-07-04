#include <stdio.h>

int main(void) {
    int n, r, distx, disty, tmp;
    printf("Enter the number n:\n");
    scanf("%d", &n);
    printf("Enter the number r:\n");
    scanf("%d", &r);
    if(r >= n){
        printf("r cannot be greater or equal to n. Enter r again:\n");
        scanf("%d", &r);
    }
    int f[n + 2*r][n + 2*r];
    for(int i = 0; i < (n + 2*r); i++) {
        for (int j = 0; j < (n + 2*r); j++) {
            f[i][j] = 0;
        }
    }
    for(int i = r; i < (n+r); i++)
        for(int j = r; j < (n+r); j++){
            distx = (i-r);
            disty = (j-r);
            printf("Enter the number to position[%d][%d]:\n", distx, disty);
            scanf("%d", &f[i][j]);
    }
    printf("\n");
    printf("Your F matrix:\n");
    for(int i = r; i < (n+r); i++) {
        for (int j = r; j < (n+r); j++) {
            printf("%d\t", f[i][j]);
        }
        printf("\n");
    }
    int w[n + 2*r][n + 2*n];
    for(int i = 0; i < (n + 2*r); i++) {
        for (int j = 0; j < (n + 2*r); j++) {
            w[i][j] = 0;
        }
    }
    for(int i = r; i < (n+r); i++){
        for(int j = r; j < (n+r); j++){
            tmp = 0;
            for(int x = i-r; x <= i+r; x++){
                for(int y = j-r; y <= j+r; y++){
                   tmp += f[x][y];
                 }
             }
             w[i][j] = tmp;
            }
        }
    printf("\n");
    printf("Your W matrix (neighbour matrix):\n");
    for(int i = r; i < (n+r); i++) {
        for (int j = r; j < (n+r); j++) {
            printf("%d\t", w[i][j]);
        }
        printf("\n");
    }
    return 0;
}

