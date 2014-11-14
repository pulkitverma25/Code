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

	fahr=lower;
	while(fahr<=upper)
	{
		celcius=(5.0/9.0)*(fahr-32);
		printf("%3.0f\t%6.1f\n",fahr,celcius);
		fahr += step;
	}
	
	return 0;
}
