/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/zenhacks/challenges/strange-grid

A strange grid has been recovered from an old book. It has 5 columns and infinite number of rows. The bottom row is considered as the first row. First few rows of the grid are like this:

..............

..............

20 22 24 26 28

11 13 15 17 19

10 12 14 16 18

 1  3  5  7  9

 0  2  4  6  8

The grid grows upwards forever!

Your task is to find the integer in cth column in rth row of the grid.

Input Format

There will be two integers r and c separated by a single space.

Constraints

1≤r≤2 * 109

1≤c≤5

Rows are indexed from bottom to top and columns are indexed from left to right.

Output Format

Output the answer in a single line.

Sample Input

6 3

Sample Output

25

Explanation

The number in the 6th row and 3rd column is 25.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    ll r,c;
    cin>>r>>c;
    
    ll ans;
    if(r&1)
        ans=(r-1)*5;
    else
        ans=((r-2)*5)+1;
    
    ans+=(c-1)*2;
    
    cout<<ans<<endl;
    return 0;
}
