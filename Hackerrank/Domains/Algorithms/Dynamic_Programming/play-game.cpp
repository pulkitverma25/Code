/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/play-game

You and your friend decide to play a game using a stack consisting of N bricks. In this game, you can alternatively remove 1, 2 or 3 bricks from the top, and the numbers etched on the removed bricks are added to your score. You have to play so that you obtain the maximum possible score. It is given that your friend will also play optimally and you make the first move.

Input Format
First line will contain an integer T i.e. number of test cases. There will be two lines corresponding to each test case: first line will contain a number N i.e. number of elements in the stack and next line will contain N numbers i.e. numbers etched on bricks from top to bottom.

Output Format
For each test case, print a single line containing your maximum score.

Constraints
1 ≤ T ≤ 5
1 ≤ N ≤ 105
0 ≤ each number on brick ≤ 109

Sample Input

2
5
999 1 1 1 0
5
0 1 1 1 999

Sample Output

1001
999

Explanation

In first test case, you will pick 999,1,1. If you play in any other way, you will not get a score of 1001.
In second case, best option will be to pick up the first brick (with 0 score) at first. Then your friend will choose the next three blocks, and you will get the last brick.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll valArray[100000],sum[100000],dp[100000];

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
            cin>>valArray[n-i-1];
        
        sum[0]=dp[0]=valArray[0];
        for(int i=1;i<n;i++)
            sum[i]=valArray[i]+sum[i-1];
        
        dp[1]=sum[1];
        dp[2]=sum[2];
        
        for(int i=3;i<n;i++)
            dp[i]=max(max(sum[i]-dp[i-1],sum[i]-dp[i-2]),sum[i]-dp[i-3]);
        
        cout<<dp[n-1]<<endl;
    }
    
    return 0;
}

