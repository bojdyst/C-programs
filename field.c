#include <stdio.h>
#include <math.h>

int surface(int a, int b, int c, int d){
    return (abs(c - a) + 1)*(abs(d - b) + 1);
}

int main(void){
    int n, y, tmp = 0, result = 0;
    printf("Insert the n number:\n");
    scanf("%d", &n);
    int field[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Insert the number to position [%d][%d]:\n", i, j);
            scanf("%d", &field[i][j]);
        }
    }
    printf("\n");
    printf("Your field-matrix\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int first_one = n;
            int q = j;
            for (int x = i; x < n; x++) {
                q = j;
                if(field[x][q] == 1)
                    break;
                for (y = j; y < first_one; y++) {
                    if (field[x][y] == 1 && y != 0) {
                        first_one = y;
                        break;
                    }
                }
                y--;
                tmp = surface(i, j, x, y);
                if (tmp > result)
                    result = tmp;
            }
        }
    }
    printf("\n");
    printf("The biggest field has the following surface area:\n");
    printf("%d", result);
    printf("\n");
    return 0;
}

