/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
// Implement Tower of Hanoi using Recursion

#include <stdio.h>

void towerOfHanoi(int , char , char , char);

int main()
{
	long int num;

	printf("Enter the number: ");
	scanf("%ld",&num);
	towerOfHanoi(num,'A','C','B');

	return 0;
}

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg)
{
	if (n==1)
	{
		printf("Move disk 1 from Peg %c to Peg %c\n",fromPeg, toPeg);
		return;
	}
	
	towerOfHanoi(n-1,fromPeg,auxPeg,toPeg);

	printf("Move disk %d from Peg %c to Peg %c\n",n,fromPeg, toPeg);

	towerOfHanoi(n-1,auxPeg,toPeg,fromPeg);

	return;
}
