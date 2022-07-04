#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number:\n");
    scanf("%d", &n);
    int f1 = 0;
    int f2 = 1;

    for(int i=0; i <=n; i++)
    {
        if(n == f1*f2)
        {
            printf("YES\n");
            return;
        }
        else
        {
            f2 += f1;
            f1 = f2 - f1;
        }
    }
    printf("NO\n");
    return 0;
}
