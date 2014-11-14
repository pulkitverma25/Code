/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
A number is given and you had to translate it to string form (Indian system – lakhs, crores etc. not millions, billions etc .) The word “and” had to be added at the appropriate place (after 100s place if there was a digit in 10s or 1s place)
101 => one hundred and one
2311 => two thousand three hundred and eleven
900020 => nine lakh and twenty
35 => thirty five
3 => three
1<=N<=999999999
*/

#include <stdio.h>
#include <string.h>
typedef long long int ll;

char *digits[]={"one","two","three","four","five","six","seven","eight","nine"};
char *digits2[]={"eleven", "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *tens[]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

void toWord(ll num, int isAnd)
{
	if(num<100 && isAnd)
	{	
		printf("and ");
		isAnd=0;
	}
	
	if(num<10)
		printf("%s ",digits[num-1]);
	else if(num<20)
		printf("%s ",digits2[num-10]);
	else if(num<100)
	{
		printf("%s ",tens[(num/10)-1]);
		toWord(num%10,isAnd);
	}
	else if(num<1000)
	{
		toWord(num/100,0);
		printf("hundered ");
		toWord(num%100,isAnd);
	}
	else if(num<100000)
	{
		toWord(num/1000,0);
		printf("thousand ");
		toWord(num%1000,isAnd);	
	}
	else if(num<10000000)
	{
		toWord(num/100000,0);
		printf("lakh ");
		toWord(num%100000,isAnd);		
	}
	else if(num<1000000000)
	{
		toWord(num/10000000,0);
		printf("crore ");
		toWord(num%10000000,isAnd);		
	}
	return;
}

int main()
{
	ll num;
	scanf(" %lld",&num);
	
	if (num==0)
		printf("zero");
	else if(num<100)
		toWord(num,0);
	else
		toWord(num,1);	
	printf("\n");

	return 0;
}

