#include <stdio.h>

int main(void)
{
    int n;
    int flag;
    int temp;
    int flag2;
    int y;
    printf("Enter the upper limit:\n");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        flag = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            flag2 = 1;
            y = i;
            temp = i % 10;
            while (y / 10 > 0)
            {
                y /= 10;
                if (temp < y % 10)
                {
                    flag2 = 0;
                    break;
                }
                temp = y % 10;
            }
            if (flag2 == 1)
            {
                printf("%d ", i);
            }
        }
    }
    return 0;
}
