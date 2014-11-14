/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int c;

	while((c = getchar()) != EOF)
	{
		putchar(c);
		
		if (c==' ')
		{
			while((c = getchar()) == ' ');

			if(c != EOF)				
				putchar(c);
			else
				break;
		}
		
	}

	return 0;
}
