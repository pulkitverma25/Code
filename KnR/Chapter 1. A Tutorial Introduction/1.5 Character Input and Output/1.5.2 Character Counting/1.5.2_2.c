/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int nc;

	for (nc=0; getchar() != EOF; ++nc);

	printf("%d\n",nc);

	return 0;
}
