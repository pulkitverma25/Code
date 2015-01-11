/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/CDSM2014/problems/CHFMAX/

You are given a string of lower case characters. You have to find the character with the most frequency. In case there are 2 such characters, consider the one with lower ASCII value.

After this replace the character with the maximum frequency with '?' (without quotes). Then, print the resulting string.

You have to do this for a number of test cases.
Input

The first line of input contains the number of test cases.

Then t lines follow, each containing a string s of lower case characters.
Output

The output contains t lines, one for each test case, each containing the resultant string for that test case.
Constraints

1<=t<=100

1<=|S|<=1000, |S| is the length of the string S.
Example

Input:
1
aba
Output:
?b?
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll hash[26];

int main()
{
	ll t;
	scanf("%lld",&t);
	
	while(t--)
	{
		memset(hash,0,sizeof(hash));
		string s;
		cin>>s;
		ll sz=s.size();
		
		for(ll i=0;i<sz;i++)
			hash[s[i]-'a']++;
		ll maxV=0;
		ll maxI=0;
		for(ll i=0;i<26;i++)
			if(maxV<hash[i])
			{
				maxV=hash[i];
				maxI=i;
			}
		
		for(ll i=0;i<sz;i++)
		{
			if(s[i]==(maxI+'a'))
				printf("?");
			else
				printf("%c",s[i]);
		}
		printf("\n");
	}
	
	return 0;
}
