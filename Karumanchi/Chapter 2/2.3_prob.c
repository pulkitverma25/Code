/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define NUM 3 //Length of string
#define K 3 //k-Ary String

void k_Ary(int , int , char [] );

int main()
{
	char A[NUM+1];
	A[NUM]='\0';

	k_Ary(NUM,K,A);

	return 0;
}

void k_Ary (int n, int k, char A[])
{
	int i;
	if (n<1)
		printf("%s\n",A);
	else
	{
		for(i=0;i<k;++i)
		{
			A[n-1]='0'+i;
			k_Ary(n-1,k,A);
		}	
	}

	return;		
}
