/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	long int nb,nt,nn;
	int c;

	nb=nt=nn=0;
	while( (c = getchar()) != EOF)
	{
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nn;
	}

	printf("Number of Blanks = %ld\n",nb);
	printf("Number of Tabs = %ld\n",nt);
	printf("Number of Newlines = %ld\n",nn);

	return 0;
}
