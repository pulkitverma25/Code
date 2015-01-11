/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/COOK51/problems/ANUARM/

 N Soldiers are lined up for a memory test. They are numbered from 0 to N-1 from left to right.

In the test, there are M rounds. In each round, Captain selects one position. Soldier at that position will be numbered 0. All the soldiers to the right of selected position will be numbered one greater than the soldier to his left. All the soldiers to the left of selected position will be numbered one greater than the soldier to his right.
eg. if N = 6 and selected position is 3, then the numbering will be [3, 2, 1, 0, 1, 2].

After M rounds, Captain asked each soldier to shout out the greatest number he was assigned during the M rounds. In order to check the correctness, Captain asked you to produce the correct values for each soldier (That is the correct value each soldier should shout out).
Input

The first line of the input contains an integer T denoting the number of test cases.
First line of each test case contains two integers, N and M.
Second line of each test case contains M integers, the positions selected by Captain, in that order.
Output

For each test case, output one line with N space separated integers.
Constraints

    1 ≤ T ≤ 10^4
    1 ≤ N ≤ 10^5
    1 ≤ M ≤ 10^5
    1 ≤ Sum of N over all testcases ≤ 10^5
    1 ≤ Sum of M over all testcases ≤ 10^5
    0 ≤ Positions selected by captain ≤ N-1 

Example

Input
2
4 1
1
6 2
2 3

Output
1 0 1 2
3 2 1 1 2 3
*/

#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
typedef long long int ll;
using namespace std;

int main()
{
	ll t;
	scanf("%lld\n",&t);

	while(t--)
	{
		ll num,n,m;
		scanf("%lld %lld",&n,&m);
		ll minI=INT_MAX,maxI=INT_MIN;
		for(ll i=0;i<m;i++)
		{
			scanf("%lld",&num);
			if(num<minI)
				minI=num;
			if(num>maxI)
				maxI=num;
		}
		for(ll i=0;i<n;i++)
			printf("%lld ",max(abs(i-minI),abs(i-maxI)));
		printf("\n");
	}
	return 0;
}
