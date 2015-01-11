/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/warm-up-1/challenges/warm-up-2

Given an n×n square matrix, find sum of all sub-squares of size k×k where k is smaller than or equal to n.

Input - First line contains no of test cases t, followed by t test cases. 1st line of each test case contains n and k. Which is followed by n rows, each row is having n values(forming n×n matrix).

t≤1001

1≤n≤101

1≤k≤n

where each value in the matrix lies between 0 to 20.

Output - For each test case, 1st row contains # printed once. That is followed by the output matrix as shown in the example.

Sample Input

2 
4 3
1 1 1 1 
2 2 2 2  
3 3 3 3 
4 4 4 4 
4 2
1 1 1 4  
2 2 2 4  
3 3 3 5 
4 4 5 5

Sample Output

#
18  18  
27  27
#
6  6  11  
10  10  14  
14  15  18  
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll mat[102][102];
ll dp[102][102];

ll sumM(ll i,ll j, ll size)
{
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    ll sum=0;
    if(i-1>=0)
    {
        sum=sumM(i-1,j,size);
        for(ll z=0;z<size;z++)
        {
            sum-=mat[i-1][j+z];
            sum+=mat[i+size-1][j+z];
        }
    }
    else if(j-1>=0)
    {
        sum=sumM(i,j-1,size);
        for(ll z=0;z<size;z++)
        {
            sum-=mat[i+z][j-1];
            sum+=mat[i+z][j+size-1];
        }
    }
    else
    {
        for(ll z=0;z<size;z++)
            for(ll c=0;c<size;c++)
                sum+=mat[z][c];
    }
    dp[i][j]=sum;
    return sum;
}


int main() {
    ll t;
    scanf("%lld",&t);
    
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        memset(mat,-1,sizeof(mat));
        
        ll n,k;
        scanf("%lld %lld",&n,&k);
        ll ansSize=n-k+1;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
                scanf("%lld",&mat[i][j]);
            
        printf("#\n");
        for(ll i=0;i<ansSize;i++)
        {
            for(ll j=0;j<ansSize;j++)
                printf("%lld  ",sumM(i,j,k));
            printf("\n");
        }
    }
    return 0;
}

