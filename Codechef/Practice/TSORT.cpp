/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/TSORT

Given the list of numbers, you are to sort them in non decreasing order.
Input

t – the number of numbers in list, then t lines follow [t <= 10^6].

Each line contains one integer: N [0 <= N <= 10^6]
Output

Output given numbers in non decreasing order.
Example

Input:

5
5
3
6
7
1

Output:

1
3
5
6
7
*/

#include <cstdio>
#include <climits>
#include <cstring>
#define RANGE 1000001

using namespace std;
typedef long long int ll;

ll count[RANGE];

int main()
{
	ll t,num;
	ll minV=INT_MAX;
	ll maxV=INT_MIN;
	scanf("%lld",&t);
	
	memset(count,0,sizeof(count));
	for(ll i=0;i<t;i++)
	{	scanf("%lld",&num);
		count[num]++;
		if(num<minV)
			minV=num;
		if(num>maxV)
			maxV=num;
	}
	for(ll i=minV;i<=maxV;i++)
		for(ll j=0;j<count[i];j++)
			printf("%lld\n",i);

	return 0;
}
