#include <stdio.h>

int main(void)
{
    int high;
    int low;
    printf("Insert the high range:\n" );
    scanf("%d", &high);
    printf("Insert the low range:\n");
    scanf("%d", &low);
    int sum;
    int number_of_elements = 0;

    for (int i=low; i <= high; ++i)
    {
        sum = 0;
        for (int j=1; j <= (i/2); ++j)
        {
            if (i % j == 0 && i !=1)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("Perfect numbers in Your range are: %d \n", sum);
            number_of_elements += 1;
        }
    }
    printf("Amount of perfect numbers in Your range: %d\n", number_of_elements);
    return 0;
}

