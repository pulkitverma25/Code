/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/problems/ONEKING

N one dimensional kingdoms are represented as intervals of the form [ai , bi] on the real line.
A kingdom of the form [L, R] can be destroyed completely by placing a bomb at a point x on the real line if L
≤ x ≤ R.

Your task is to determine minimum number of bombs required to destroy all the one dimensional kingdoms.
Input

    First line of the input contains T denoting number of test cases.
    For each test case, first line contains N denoting the number of one dimensional kingdoms.
    For each next N lines, each line contains two space separated integers ai and bi.

Output

For each test case , output an integer denoting the minimum number of bombs required.
Constraints

Subtask 1 (20 points) : 1 ≤ T ≤ 100 , 1 ≤ N ≤ 100 , 0 ≤ ai ≤ bi ≤500

Subtask 2 (30 points) : 1 ≤ T ≤ 100 , 1 ≤ N ≤ 1000 , 0 ≤ ai ≤ bi ≤ 1000

Subtask 3 (50 points) : 1 ≤ T ≤ 100 , 1 ≤ N ≤ 105, 0 ≤ ai ≤ bi ≤ 2000
Example

Input:
1
3
1 3
2 5
6 9

Output:
2

Explanation:
There are three kingdoms [1,3] ,[2,5] and [6,9]. You will need at least 2 bombs
to destroy the kingdoms. In one of the possible solutions, you can place two bombs at x = 2 and x = 6 .
*/

#include <bits/stdc++.h>

#define MAXV 100005
#define LIMIT 20001

using namespace std;
typedef long long int ll;

struct bombLoc
{
	ll start;
	ll end;
};
typedef struct bombLoc loc;

loc lArray[MAXV];
ll arr[LIMIT];

bool compare(loc a, loc b)
{
	if(a.end==b.end)
		return a.start<b.start;
	return a.end<b.end;
}

int main()
{
	ll t;
	scanf("%lld ",&t);
	
	while(t--)
	{
		ll n,count=0;
		scanf("%lld ",&n);
		
		memset(lArray,0,sizeof(lArray));	
		memset(arr,-1,sizeof(arr));
		
		for(ll i=0;i<n;i++)
		{
			ll l,r;
			scanf("%lld %lld ",&lArray[i].start, &lArray[i].end);
		}
		
		ll maxLoc=-1;
		
		for(ll i=0;i<n;i++)
			arr[lArray[i].end]=max(arr[lArray[i].end],lArray[i].start);
		
		for(ll i=0;i<LIMIT;i++)
			if(maxLoc<arr[i])
			{
				count++;
				maxLoc=i;
			}
		
		printf("%lld\n",count);
	}
	
	return 0;
}
