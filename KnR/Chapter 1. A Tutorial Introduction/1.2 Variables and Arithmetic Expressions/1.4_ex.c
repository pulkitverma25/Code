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
	printf("Celcius to Fahrenheit Conversion Table\n");
	printf("______________________________________\n\n");
	printf("Celcius  Fahrenheit\n");
	celcius=lower;
	while(celcius<=upper)
	{
		fahr=(9.0*celcius/5.0)+32;
		printf("%5.0f\t%8.1f\n",celcius,fahr);
		celcius += step;
	}
	printf("______________________________________\n\n");
	
	return 0;
}
