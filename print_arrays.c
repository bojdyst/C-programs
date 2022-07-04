#include <stdio.h>

void printing_array(int t[], int n, int k, int m) {
    if (k == 0 && m == 1){
        for (int p = (n-1); p >= 0; p--) {
            printf("%d ", t[p]);
        }
    }
    else {
        if (m == 1) {
            for (int p = k; p >= 0 ; p--) {
                printf("%d ", t[p]);
            }
            for (int p = (n-1); p >= (k+1) ; p--) {
                printf("%d ", t[p]);
            }
        }
        else if (m == 0) {
            for (int p = k; p < n; p++) {
                printf("%d ", t[p]);
            }
            for (int p = 0; p < k; p++) {
                printf("%d ", t[p]);
            }
        }
    }

}

int main(void){
    int n, k, m;
    printf("Enter length of the array:\n");
    scanf("%d", &n);
    int t[n];
    printf("Enter elements to fill array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    printf("Enter the k index:\n");
    scanf("%d", &k);
    if (k > (n-1)){
        printf("Enter the k index again so that it isn't beyond the range:\n");
        scanf("%d", &k);
    }

    printf("Enter the 'm' value (0 if You would like to print elements ahead; or 1 to print them backward):\n");
    scanf("%d", &m);

    printf("The final array:\n");
    printing_array(t, n, k, m);
    printf("\n");
    return 0;
}

