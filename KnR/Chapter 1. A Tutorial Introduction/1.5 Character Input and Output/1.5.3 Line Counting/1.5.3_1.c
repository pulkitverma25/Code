/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int c,nl;
	
	nl=0;
	while((c = getchar()) != EOF)
	{
		putchar(c);
		if (c=='\n')
		{
			printf("HERE\n");
			++nl;
		}
	}

	printf("%d\n",nl);

	return 0;
}
