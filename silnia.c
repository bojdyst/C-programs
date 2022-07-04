#include <stdio.h>

int main(void){
    int n, temp, counter = 0;
    printf("Enter the number to get its factorial:\n");
    scanf("%d", &n);
    int tab[3000];
    for(int i = 0; i < 3000; i++){
        tab[i] = 0;
    }
    tab[0] = 1;
    for(int i = n; i >= 2; i--) {
        temp = 0;
        for(int j = 0; j <= counter; j++) {
            temp = (tab[j] * i) + temp;
            tab[j] = temp%10;
            temp = temp/10;
        }
        while (temp > 0) {
            tab[++counter] = temp%10;
            temp = temp/10;
        }
    }
    printf("Factorial of number %d is: ", n);
    for(int i = counter; i >= 0; i--)
        printf("%d",tab[i]);
    printf("\n");
    return 0;
}


