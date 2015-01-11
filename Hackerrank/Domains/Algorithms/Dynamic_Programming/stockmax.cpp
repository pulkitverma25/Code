/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/stockmax

Your algorithms have become so good at predicting the market that you now know what the share price of Wooden Orange Toothpicks Inc. (WOT) will be for the next N days.

Each day, you can either buy one share of WOT, sell any number of shares of WOT that you own, or not make any transaction at all. What is the maximum profit you can obtain with an optimum trading strategy?

Input

The first line contains the number of test cases T. T test cases follow:

The first line of each test case contains a number N. The next line contains N integers, denoting the predicted price of WOT shares for the next N days.

Output

Output T lines, containing the maximum profit which can be obtained for the corresponding test case.

Constraints

1 <= T <= 10
1 <= N <= 50000

All share prices are between 1 and 100000

Sample Input

3
3
5 3 2
3
1 2 100
4
1 3 1 2

Sample Output

0
197
3

Explanation

For the first case, you cannot obtain any profit because the share price never rises.
For the second case, you can buy one share on the first two days, and sell both of them on the third day.
For the third case, you can buy one share on day 1, sell one on day 2, buy one share on day 3, and sell one share on day 4.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() 
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll tempMax=arr[n-1],tempSum=0,profit=0;
        for(ll i=n-2;i>=0;i--)
            if(tempMax>arr[i])
                tempSum+=(tempMax-arr[i]);
            else
            {
                profit+=tempSum;
                tempMax=arr[i];
                tempSum=0;
            }
        
        if(arr[0]<tempMax)
            profit+=tempSum;
        
        cout<<profit<<endl;
    }
    return 0;
}

