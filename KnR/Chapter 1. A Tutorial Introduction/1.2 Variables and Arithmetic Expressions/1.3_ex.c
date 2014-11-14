/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	float fahr,celcius;
	int lower,upper,step;

	lower=0;
	upper=300;
	step=20;

	printf("______________________________________\n\n");
	printf("Fahrenheit to Celcius Conversion Table\n");
	printf("______________________________________\n\n");
	printf("Fahrenheit  Celcius\n");
	fahr=lower;
	while(fahr<=upper)
	{
		celcius=(5.0/9.0)*(fahr-32);
		printf("%6.0f\t%10.1f\n",fahr,celcius);
		fahr += step;
	}
	printf("______________________________________\n\n");
	
	return 0;
}
