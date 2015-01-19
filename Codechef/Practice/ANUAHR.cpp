/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/problems/ANUAHR

Abhijeet loves to play with rectangles. Today he has N rectangles of various sizes with him. He started to arrange them on the coordinate plane such that the area of intersection is maximized. However, he never rotated the rectangles he had, he only moved them here and there.

Abhijeet soon realized that the game was boring and decided to introduce a modification. He decided to remove atmost M of those rectangles and arrange others on coordinate plane such that the area of intersection is maximized.

Given the dimensions of N rectangles and M, can you answer maximum possible area of intersection with above rules?

Note: If all the rectangles are removed, the area of intersection is considered as 0.
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.First line of each test case has two integer N and M. N lines follow, each has two integers representing the length and breadth of the rectangle.
Output

For each test case, output a single line containing the required answer.
Constraints

    1 ≤ T ≤ 105
    1 ≤ N ≤ 105
    0 ≤ M ≤ N
    1 ≤ Rectangle Dimensions ≤ 109
    1 ≤ Sum of N over all test cases ≤ 106

Example

Input:
3
1 1
10 10
2 0
5 10
5 5
2 1
1 1
2 2

Output:
100
25
4

Explanation

Example case 1

Abhijeet has only one rectangle. He can remove it, but then the area will be 0. Optimal way is not to remove it. Area = 10 * 10 = 100

Example case 2

Abhijeet cannot remove any rectangles in this case. He can however, place them such that the smaller 5 by 5 rectangle is completely inside the larger 5 by 10 rectangle. Then the area of intersection is 5 * 5 = 25

Example case 3

Abhijeet can remove atmost 1 rectangles in this case. He can remove the smaller rectangle of size 1 by 1. He is then left with 2 by 2 rectangle of area 4.
*/

//Solved using editorial

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

pair <ll,ll> arr[100000];

int main()
{
	ll t;
	scanf("%lld ",&t);
	
	while(t--)
	{
		ll n,m,ans=0;
		scanf("%lld %lld ",&n,&m);
		
		multiset <ll> mSet;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld %lld",&arr[i].first,&arr[i].second);
			mSet.insert(arr[i].second);
		}
		
		sort(arr,arr+n);
		
		if(m==n)
			m--;
			
		for(ll i=0;i<m;i++)
			mSet.erase(mSet.find(arr[i].second));
		
		for(ll i=m-1;i>=-1;i--)
		{
			ll tempAns=*(mSet.begin())*arr[i+1].first;
			ans=max(ans,tempAns);
			
			if(i==-1)
				break;
			
			mSet.insert(arr[i].second);
			mSet.erase(mSet.begin());
		}
		
		printf("%lld\n",ans);
		
	}

	return 0;
}
