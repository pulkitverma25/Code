/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/OCT14/problems/PRPOTION/

 Naturally, the magical girl is very good at performing magic. She recently met her master wizard Devu, who gifted her R potions of red liquid,
B potions of blue liquid, and G potions of green liquid.

    The red liquid potions have liquid amounts given by r[1], ..., r[R] liters.
    The green liquid potions have liquid amounts given by g[1], ..., g[G] liters.
    The blue liquid potions have liquid amounts given by b[1], ..., b[B] liters.

She want to play with the potions by applying magic tricks on them. In a single magic trick, she will choose a particular color. Then she will pick all the potions of the chosen color and decrease the amount of liquid in them to half (i.e. if initial amount
of liquid is x, then the amount after decrement will be x / 2 where division is integer division, e.g. 3 / 2 = 1 and 4 / 2 = 2).

Because she has to go out of station to meet her uncle Churu, a wannabe wizard, only M minutes are left for her. In a single minute, she can perform at most one magic trick. Hence, she can perform at most M magic tricks.

She would like to minimize the maximum amount of liquid among all of Red, Green and Blue colored potions. Formally Let v be the maximum value of amount of liquid in any potion. We want to minimize the value of v.
Please help her.
Input

First line of the input contains an integer T denoting the number of test cases.
Then for each test case, we have four lines.

The first line contains four space separated integers R, G, B, M. The next 3 lines will describe the amount of different color liquids (r, g, b), which are separated by space.
Output

For each test case, print a single integer denoting the answer of the problem.
Constraints

    1 ≤ T ≤ 1000
    1 ≤ R, G, B, M ≤ 100
    1 ≤ r[i], g[i], b[i] ≤ 10^9

Example

Input:
3
1 1 1 1
1
2
3
1 1 1 1
2
4
6
3 2 2 2
1 2 3
2 4
6 8
Output:
2
4
4

Explanation

Example case 1. Magical girl can pick the blue potion and make its liquid amount half. So the potions will now have amounts 1 2 1. Maximum of these values is 2. Hence answer is 2.
*/

#include <cstdio>
#include <algorithm>

typedef long long int ll;
using namespace std;

int main()
{
	ll t;
	scanf("%lld\n",&t);

	while(t--)
	{
		ll rMax=0,gMax=0,bMax=0,m,r,g,b,temp;
		scanf("%lld %lld %lld %lld\n",&r,&g,&b,&m);

		for(ll i=0;i<r;i++)
			scanf("%lld ",&temp),rMax=max(rMax,temp);
		
		for(ll i=0;i<g;i++)
			scanf("%lld ",&temp),gMax=max(gMax,temp);
		
		for(ll i=0;i<b;i++)
			scanf("%lld ",&temp),bMax=max(bMax,temp);
		
		for(ll j=0;j<m;j++)
		{
			ll maxVal=max(max(rMax,bMax),gMax);
			if (maxVal==rMax)
				rMax>>=1;
			else if (maxVal==gMax)
				gMax>>=1;
			else
				bMax>>=1;
		}

		printf("%lld\n",max(max(rMax,bMax),gMax));
	}
	return 0;
}
