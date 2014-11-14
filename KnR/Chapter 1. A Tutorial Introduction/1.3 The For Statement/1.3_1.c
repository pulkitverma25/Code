/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	float fahr;

	for(fahr=0;fahr<=300;fahr+=20)
		printf("%6.0f\t%10.1f\n",fahr,(5.0/9.0)*(fahr-32));
	
	return 0;
}
