/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/FEB14/problems/LCPESY/

As we all know, Chef is cooking string for long days, his new discovery on string is the longest common pattern length. The longest common pattern length between two strings is the maximum number of characters that both strings have in common. Characters are case sensitive, that is, lower case and upper case characters are considered as different. Note that characters can repeat in a string and a character might have one or more occurrence in common between two strings. For example, if Chef has two strings A = "Codechef" and B = "elfedcc", then the longest common pattern length of A and B is 5 (common characters are c, d, e, e, f).

Chef wants to test you with the problem described above. He will give you two strings of Latin alphabets and digits, return him the longest common pattern length.
Input

The first line of the input contains an integer T, denoting the number of test cases. Then the description of T test cases follows.

The first line of each test case contains a string A. The next line contains another character string B.
Output

For each test case, output a single line containing a single integer, the longest common pattern length between A and B.
Constraints

    1 ≤ T ≤ 100
    1 ≤ |A|, |B| ≤ 10000 (104), where |S| denotes the length of the string S
    Both of A and B can contain only alphabet characters (both lower and upper case) and digits

Example

Input:
4
abcd
xyz
abcd
bcda
aabc
acaa
Codechef
elfedcc

Output:
0
4
3
5

Explanation

Example case 1. There is no common character.

Example case 2. All the characters are same.

Example case 3. Three characters (a, a and c) are same.

Example case 4. This sample is mentioned by the statement.
*/

#include <stdio.h>

int main()
{
	int t;

	scanf("%d\n",&t);
	
	while(t--)
	{
		int i,count=0,aCount[62],bCount[62];
		char a,b;

		for(i=0;i<62;i++)
			aCount[i]=bCount[i]=0;		


		while((a=getchar()) != '\n')
		{
			if(a>=48 && a<=57)
				aCount[a-48]++;
			else if (a>=65 && a<=90)
				aCount[a-65+10]++;
			else if (a>=97 && a<=122)
				aCount[a-97+36]++;
		}
		
		while((b=getchar()) != '\n')
		{
			if(b>=48 && b<=57)
				bCount[b-48]++;
			else if (b>=65 && b<=90)
				bCount[b-65+10]++;
			else if (b>=97 && b<=122)
				bCount[b-97+36]++;
		}
		count=0;
		for(i=0;i<62;i++)
			count+=((aCount[i]<=bCount[i])?aCount[i]:bCount[i]);
		printf("%d\n",count);
	}

	return 0;
}

