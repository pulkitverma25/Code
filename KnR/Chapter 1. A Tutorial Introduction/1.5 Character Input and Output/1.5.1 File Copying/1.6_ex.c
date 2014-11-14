/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int c;

	while(c= getchar() != EOF)
		printf("%d",c);
	printf("%d\n",c);

	return 0;
}
