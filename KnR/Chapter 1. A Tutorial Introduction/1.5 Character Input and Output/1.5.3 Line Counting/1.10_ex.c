/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int c;

	while((c=getchar()) != EOF)
	{
		if(c=='\t')
			printf("\\t");
		else if (c== '\b' )
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			printf("%c",c);
	}

	return 0;
}
