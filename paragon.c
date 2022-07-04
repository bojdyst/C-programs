#include  <stdio.h>

int main(void)
{
	float a; /*cena jednostkowa netto*/ 
	float x; /*liczba sztuk*/
	float p; /*wartosc podatku vat w procentach*/

	printf("Enter the netto price: \n");
	scanf("%f", &a);
	printf("Enter the amount of the product: \n");
	scanf("%f", &x);
	printf("Enter the VAT tax in %: \n");
	scanf("%f", &p);

	float netto_value = a*x;
	float VAT = 0.01*p*a*x;
	float brutto_value = a*x + 0.01*a*x*p;

	printf("The netto value of your products: %.2f \n", netto_value);
	printf("The amount of VAT tax: %.2f \n", VAT);
	printf("The brutto value of your products: %.2f \n", brutto_value);

	return 0;
}


