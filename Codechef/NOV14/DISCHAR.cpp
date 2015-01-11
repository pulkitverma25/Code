/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/NOV14/problems/DISCHAR/

You have initially a string of N characters, denoted by A1,A2...AN. You have to print the size of the largest subsequence of string A such that all the characters in that subsequence are distinct ie. no two characters in that subsequence should be same.

A subsequence of string A is a sequence that can be derived from A by deleting some elements and without changing the order of the remaining elements.
Input

First line contains T, number of testcases. Each testcase consists of a single string in one line. Each character of the string will be a small alphabet(ie. 'a' to 'z').
Output

For each testcase, print the required answer in one line.
Constraints

    1 ≤ T ≤ 10
    Subtask 1 (20 points):1 ≤ N ≤ 10
    Subtask 2 (80 points):1 ≤ N ≤ 105

Example

Input:
2
abc
aba

Output:
3
2

Explanation

For first testcase, the whole string is a subsequence which has all distinct characters.

In second testcase, the we can delete last or first 'a' to get the required subsequence. 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool arr[26];

int main()
{
	ll t;
	scanf("%lld\n",&t);
	
	while(t--)
	{
		ll count=0;
		memset(arr,0,sizeof(arr));
		char c;
		while((c=getchar())!=EOF)
		{
			if(c=='\n' )
				break;
			if(!arr[c-'a'])
			{
				arr[c-'a']=true;
				count++;
			}
		}
		printf("%lld\n",count);
	}

	return 0;
}
