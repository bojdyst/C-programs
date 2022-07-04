#include <stdio.h>

int main(void)
{
	int N;
	int i;
	int silnia = 1;
	
	printf("Enter the number to get its factorial: \n");
	scanf("%d", &N);

	for (i=1; i <= N; i++)
	{
		silnia = silnia*i;
	}

	printf("The factorial of %d is: %d \n", N, silnia);
	
	return 0;
}	

