/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
// Print numbers from num to 1 in revere order using Recursive Function

#include <stdio.h>

void Print(int );

int main()
{
	int num;

	printf("Enter the number: ");
	scanf("%d",&num);
	Print(num);

	return 0;
}

void Print (int n)
{
	if (n==0)
		return;
	else
	{
		printf("%d\n",n);
		return Print(n-1);
	}
}
