/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/ANUMLA

 Mahesh got a beautiful array named A as a birthday gift from his beautiful girlfriend Namratha. There are N positive integers in that array. Mahesh loved the array so much that he started to spend a lot of time on it everyday. One day, he wrote down all possible subsets of the array. Then for each subset, he calculated the sum of elements in that subset and wrote it down on a paper. Unfortunately, Mahesh lost the beautiful array :(. He still has the paper on which he wrote all subset sums. Your task is to rebuild beautiful array A and help the couple stay happy :)
Input

The first line of the input contains an integer T denoting the number of test cases.
First line of each test case contains one integer N, the number of elements in A.
Second line of each test case contains 2^N integers, the values written on paper
Output

For each test case, output one line with N space separated integers in non-decreasing order.
Constraints

    1 ≤ T ≤ 50
    1 ≤ N ≤ 15
    0 ≤ Values on paper ≤ 10^9
    All input values are valid. A solution always exists 

Example

Input
2
1
0 10
2
0 1 1 2

Output
10
1 1

Explanation

Test case #2
For the array [1,1], possible subsets are {}, {1}, {1}, {1,1}, respective sums are 0, 1, 1, 2.
*/

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll a[16],b[65536],c[65536];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		ll n;
		scanf("%lld",&n);

		ll lim=(1<<n);
		for(ll i=0;i<lim;i++)
			scanf("%lld",&b[i]);
	
		sort(b,b+lim);

		multiset<ll>mS;
		ll ptr=0;
		ll cptr=0;
		for(ll i=1;i<lim;i++)
		{
			ll temp=-1;
			if(!mS.empty())
			{
				temp=*mS.begin();
			}
		
			if(b[i]==temp)
			{
				mS.erase(mS.begin());
			}
			else
			{
				a[ptr]=b[i];
				ll mptr=cptr;
				for(ll j=0;j<mptr;j++)
				{
					c[cptr]=c[j]+a[ptr]; 
					mS.insert(c[cptr]);
					cptr++;
				}
				c[cptr++]=a[ptr];
				ptr++;
			}
		}
		for(ll i=0;i<ptr;i++)
			printf("%lld ",a[i]);
		printf("\n");
	}

	return 0;
}
