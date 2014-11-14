/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
// Implement factorial using Recursion

#include <stdio.h>

long int fact(long int );

int main()
{
	long int num;

	printf("Enter the number: ");
	scanf("%ld",&num);
	printf("\n %ld! = %ld\n",num,fact(num));

	return 0;
}

long int fact (long int n)
{
	if (n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}
