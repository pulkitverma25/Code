/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/FCTRL2

You are asked to calculate factorials of some small positive integers.

Input


An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.

Output


For each integer n given at input, display a line with the value of n!

Example
Sample input:

4
1
2
5
3

Sample output:

1
2
120
6
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDigitCount(int num)
{
	int count=0;
	while(num%10!=0 || num/10>0)
	{
		count++;
		num/=10;
	}

	return count;
}

char* multiply(char *num1, int num2)
{
	int temp=0,currNum,index=0,digitCount=0;

	while(num1[index]!='\0')
	{
		currNum=((num1[index]-48)*num2)+temp;
		num1[index]=(currNum%10)+48;
		temp=currNum/10;
		index++;
	}

	if(num1[index]=='\0')
	{
		digitCount=getDigitCount(temp);
		num1 = (char *) realloc(num1, (strlen(num1)+digitCount+1)*sizeof(char));
		while(digitCount--)
		{
			num1[index]=(temp%10)+48;
			temp=temp/10;
			index++;
		}
	}

	num1[index]='\0';
	return num1;
}

void printOutput(char* fact, int i)
{
	if (fact[i]=='\0')
		return;
	else
	{
		printOutput(fact,i+1);
		printf("%c", fact[i]);
	}
	return;
}

int main()
{
	int t,num,i;
	char *fact;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&num);
		fact=(char*)malloc(sizeof(char)*2);
		fact[0]='1';
		fact[1]='\0';

		for(i=2;i<=num;i++)
			fact=multiply(fact,i);

		printOutput(fact,0);
		printf("\n");
		free(fact);
	}

	return 0;
}
