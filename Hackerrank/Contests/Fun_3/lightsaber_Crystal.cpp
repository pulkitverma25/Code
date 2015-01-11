/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun-3-0/challenges/lightsaber-crystal

Master Yoda is explaining the complex task of making lightsaber to his students. The most powerful and sought-after gems used for making lightsabers are rare Kaiburr crystals. The Kaiburr crystals must be cut at precise locations. Through years of experience Jedis have noticed that the cost of cut is determined by the length of the crystal to be cut.

Master Yoda gave t crystals to his students. Each crystal has a note accompnying with it which lists the total number of cuts and exact locations of the cut. Help the students in finding a cutting sequence so that the overall cost is minimized.

Input Format

The first line of input contains a number t representing the number of test cases. The first line of each test case will contain a positive number l that represents the length of the crystal to be cut. You can assume l<=1000. The next line will contain the number n (n<1000), number of cuts to be made.

The next line consists of n positive numbers ci (0<ci<l) representing the places where the cuts have to be done, given in strictly increasing order.

Output Format

For each test case you have to print the cost of the optimal solution of the cutting, that is the minimum cost of cutting the given crystal.

Constraints

1<=t<=25

2<=l<=1000

1<=n<1000

0<ci<l

Sample Input

2
100
3
25 50 75
10
4
4 5 7 8

Sample Output

200
22

Sample Input 2

1
10
3
2 4 7

Sample Output 2

20

Explaination (Input 2)

In the test case, length of crystal is 10 and it is to be cut at 2, 4 and 7. There are several choices. One can be cutting first at 2, then at 4, then at 7. This leads to a cost of 10 + 8 + 6 = 24 because the first crystal was of length 10, the resulting of 8 and the last one of 6. Another choice could be cutting at 4, then at 2, then at 7. This would lead to a cost of 10 + 4 + 6 = 20, which is a better cost.
*/

#include <bits/stdc++.h>

#define FILL(a,d) memset(a,d,sizeof(a))

using namespace std;
const int inf=1000000007;
int a[1005];
int dp[10005][10005];

int f(int start,int end)
{
    if(dp[start][end]!=-1)
        return dp[start][end];
    if(end-start==1) return dp[start][end]=0;
    int mincost=inf;
    for(int i=start+1;i<end;i++)
    {
        int cost=(a[end]-a[start])+f(start,i)+f(i,end);
        mincost=min(cost,mincost);
    }
    dp[start][end]=mincost;
    return dp[start][end];
}

int main()
{
    int i,j,k,n,d,l;
	int t;
	cin>>t;
    while(t--)
    {
		cin>>l;
        
        FILL(dp,-1);
        cin>>n; 
		a[0]=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
            a[n+1]=l;
            cout<<f(0,n+1)<<endl;
    }
    return 0;
}

