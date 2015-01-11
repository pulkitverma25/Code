/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/iit-guwahati-placement-preparation-test-1/challenges/reverse-game

Akash and Akhil are playing a game. They have N balls numbered from 0 to N−1. Akhil asks Akash to reverse the position of the balls, i.e., to change the order from say, 0,1,2,3 to 3,2,1,0. He further asks Akash to reverse the position of the balls N times, each time starting from one position further to the right, till he reaches the last ball. So, Akash has to reverse the positions of the ball starting from 0th position, then from 1st position, then from 2nd position and so on. At the end of the game, Akhil will ask Akash the final position of any ball numbered K. Akash will win the game, if he can answer. Help Akash.

Input Format
The first line contains an integer T, i.e., the number of the test cases.
The next T lines will contain two integers N and K.

Output Format
Print the final index in array.

Constraints
1≤T≤50
1≤N≤105
0≤K<N

Sample Input

2
3 1
5 2

Sample Output

2
4

Explanation
For first test case, The rotation will be like this:
0 1 2 -> 2 1 0 -> 2 0 1 -> 2 0 1
So, Index of 1 will be 2.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    int t;
    scanf("%d\n",&t);
    
    while(t--)
    {
        ll n,k;
        scanf("%lld %lld\n",&n,&k);
        ll pos;
        if(n&1)
        {
            n--;
            if(k<n/2)
                pos=((k+1)<<1)-1;
            else
                pos=(n-k)<<1;
        }
        else
        {
            n--;
            if(k<=n/2)
                pos=((k+1)<<1)-1;
            else
                pos=(n-k)<<1;
        }
        
        printf("%lld\n",pos);
    }
    return 0;
}

