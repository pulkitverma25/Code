/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/NOV14/problems/PRPALN/

Given a string s. Can you make it a palindrome by deleting exactly one character? Note that size of the string after deletion would be one less than it was before.
Input

First line of the input contains a single integer T denoting number of test cases.

For each test case, you are given a single line containing string s.
Output

For each test case, print YES or NO depending on the answer of the problem.
Constraints

Subtask 1, 35 points

    1 ≤ T ≤ 100
    2 ≤ size of string s ≤ 1000
    String s contains lowercase English alphabets (ie. from 'a' to 'z'). 

Subtask 2, 65 points

    2 ≤ size of string s ≤ 10^5
    Sum of size of string s over all the input test cases won't exceed 10^6
    String s contains lowercase English alphabets (ie. from 'a' to 'z'). 

Example

Input:
4
aaa
abc
abdbca
abba

Output:
YES
NO
YES
YES

Explanation

Example case 1. Delete any one 'a', resulting string is "aa" which is a palindrome.

Example case 2. It is not possible to delete exactly one character and having a palindrome.

Example case 3. Delete 'c', resulting string is "abdba" which is a palindrome.

Example case 4. Delete 'b', resulting string is "aba" which is a palindrome. 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

string str;
bool done;
bool isPalin(ll s, ll e)
{
	while(s<e)
	{
		if(str[s]==str[e])
		{
			s++;
			e--;
		}
		else if(!done)
		{
			done=true;
			return isPalin(s+1,e) || isPalin(s,e-1);
		}	
		else
			return false;	
		
	}	
}

int main()
{
	ll t;
	scanf("%lld\n",&t);
	
	while(t--)
	{
		done=false;
		cin>>str;
		if(isPalin(0,str.size()-1))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
