/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/PHYSICS

The Physics teacher in Tanu's class is teaching concepts of a bouncing ball. The rubber ball that she is using has the property that if the ball is dropped from height H then, it bounces back to maximum height H/F. So after first bounce it rises up to maximum height H/F, after second bounce to maximum height H/F2, after third bounce to maximum height H/F3, and so on.

The class has N children, and the teacher wants to select two children such that when the taller child drops the ball from his height, ball reaches a maximum height equal to the height of the shorter child after some (possibly zero) number of bounces. Note that zero bounces mean heights of the two children will be same. Given the heights of the children in the class Height[i], can you tell how many ways are there for the teacher to select two children for the demonstration? Note that when heights are same, the pair is only counted once (See first example for further clarification).
Input

First line contains T, number of testcases. Then 2*T lines follow, 2 per testcase.
First line of each testcase consists of two space-separated intergers N and F. Second line of each testcase contains N space-separated integers representing the array Height.
Output

For each testcase, print a single line containing the answer to the problem.
Constraints

    For 40 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 103, 2 ≤ F ≤ 109, 1 ≤ Height[i] ≤ 109
    For 60 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 104, 2 ≤ F ≤ 109, 1 ≤ Height[i] ≤ 109

Example

Input:

2
3 2
2 2 2
3 2
2 1 4


Output:

3
3


Explanation:

    In the first case, the three pairs are (child 1, child 2), (child 2, child 3) and (child 1, child 3).
    For the second case also, the three pairs are (child 1, child 2), (child 2, child 3) and (child 1, child 3).
*/

#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
ll h[10000];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll f;
		int n;
		scanf("%d",&n);
		scanf("%lld",&f);

		for(int i=0;i<n;i++)
			scanf("%lld",&h[i]);

		sort(h,h+n);

		map<int, int> mMap;
		for(int i=0;i<n;i++)
			mMap[h[i]]++;
		int maxV=h[n-1];


		ll count=0;
		for(int i=0;i<n;i++)
		{
			mMap[h[i]]--;
			for(ll j=h[i];j<=maxV;j*=f)
				count+=mMap[j];
		}
	
		printf("%lld\n",count);
	}
	return 0;
}
