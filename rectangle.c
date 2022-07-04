#include <stdio.h>
#define max 200

/*description:
white colour is represented by 0;
black colour is represented by 1;
*/

int main(void){
    int tab[max][max], n, sum = 0;
    printf("Enter the number of rectangles:\n");
    scanf("%d", &n);
    for(int t = 0; t <= 199; t++){
        for(int k = 0; k <= 199; k++){
            tab[t][k] = 0;
        }
    }
    while(n > 0){
        int x1, y1, x2, y2;
        printf("Enter coordinates: x1, y1, x2, y2\n");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int tmpx = x1;
        int tmpy = y1;
        if(x2 < x1){
            x1 = x2;
            x2 = tmpx;
        }
        if(y2 < y1){
            y1 = y2;
            y2 = tmpy;
        }
        for(int i = (x1+100); i < (x2+100); i++) {
            for (int j = (y1+100); j < (y2+100); j++) {
                        if (tab[j][i] == 0) {
                            tab[j][i] = 1;
                        }
                        else if (tab[j][i] == 1) {
                            tab[j][i] = 0;
                        }

                }
        }
        n--;
    }
    for(int i = 0; i <= 199; i++){
        for(int j = 0; j <= 199; j++){
            if(tab[i][j] == 1){
                sum += 1;
            }
        }
    }
    printf("There is following number of black squares\n%d\n", sum);
    return 0;
}
