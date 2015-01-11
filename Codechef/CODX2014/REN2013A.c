/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/CODX2014/problems/REN2013A/

Given two integers A and B that are not necessarily in base-10, find the smallest possible A + B in base-10.

For example,
A = 213, possibly base-4 (39 in base-10)
B = 4721, possibly base-8 (2513 in base-10)
A + B = 39 + 2513 = 2552 
Input

First line of the input contains a positive integer T (1 <= T <= 100), the number of cases. Each case contains
two positive integers A and B. A and B will contain at most 5 digits, each digit will be between 0 and 9,
inclusive, and no leading zeroes.
Output

For each case, output an integer in base-10 denoting the smallest possible A + B.
Example

Input:
3
213 4721
1001 90
638 241

Output:
2552
99
592
*/

#include <stdio.h>
#include <stdlib.h>

int findMaximumDigit(int x) 
{
    int max=-1; 
    while (x>0)
	{
        int digit = x %10; 
        x=x/10;        
        if(max < digit)    
            max=digit;    
    }
    return max;
}

int main()
{
	int t,num1,num2,maxDigit1,maxDigit2,newNum1,newNum2,i;
	char number1[6],number2[6];
	scanf("%d\n",&t);
	
	for(i=0;i<t;i++)
	{
		scanf("%s %s\n",number1,number2);
		num1=atoi(number1);
		num2=atoi(number2);
		
		maxDigit1=findMaximumDigit(num1);
		maxDigit2=findMaximumDigit(num2);
		char *pEnd;
		newNum1=strtol (number1,&pEnd,maxDigit1+1);
		newNum2=strtol (number2,&pEnd,maxDigit2+1);
		
		printf("%d\n",newNum1+newNum2);
	}
	
	return 0;
}
