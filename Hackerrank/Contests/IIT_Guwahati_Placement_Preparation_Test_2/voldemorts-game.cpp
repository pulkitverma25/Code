/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/iit-guwahati-placement-preparation-test-02/challenges/voldemorts-game

Voldemort loves playing with numbers. He only knows single digit prime numbers yet, i.e., 2, 3, 5 and 7. But voldemort grew rather bored of such numbers, so he came up with a few games that were connected with them.

Voldemort wants to find the smallest number of length n, such that it is simultaneously divisible by all numbers he already knows (2, 3, 5 and 7).

A number's length is the number of digits in its decimal representation without leading zeros.

Input

A single input line contains a single integer n (1 ≤ n ≤ 10^5).

Output

Print a single integer — the answer to the problem without leading zeroes, or "-1" (without the quotes), if the number that meet the problem condition does not exist.

Sample Input 01

2

Sample Output 01

-1

Sample Input 02

4

Sample Output 02

1050
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    ll n;
    scanf("%lld",&n);
    
    if(n<3)
    {
        printf("-1\n");
        return 0;
    }
    else if(n==3)
    {
        printf("210\n");
        return 0;        
    }
    
    char* minV[]={"050","080","170","020","200","110"};
    printf("1");
    ll c=n-4;
    for(ll i=0;i<c;i++)
        printf("0");
    printf("%s\n",minV[(n-4)%6]);
    
    return 0;
}

