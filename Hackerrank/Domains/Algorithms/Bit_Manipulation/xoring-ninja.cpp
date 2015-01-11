/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/xoring-ninja

Given a list containing N integers, calculate the XOR_SUM of all the non-empty subsets of the list and print the value of sum % (109 + 7).

XOR operation on a list (or a subset of the list) is defined as the XOR of all the elements present in it.
E.g. XOR of list containing elements {A,B,C} = ((A^B)^C), where ^ represents XOR.

E.g. XOR_SUM of list A having three elements {X1, X2, X3} can be given as follows.
All non-empty subsets will be {X1, X2, X3, (X1,X2), (X2,X3), (X1,X3), (X1,X2,X3)}

XOR_SUM(A) = X1 + X2 + X3 + X1^X2 + X2^X3 + X1^X3 + ((X1^X2)^X3)

Input Format
An integer T, denoting the number of testcases. 2T lines follow.
Each testcase contains two lines, first line will contains an integer N followed by second line containing N integers separated by a single space.

Output Format
T lines, ith line containing the output of the ith testcase.

Constraints
1 <= T <= 5
1 <= N <= 105
0 <= A[i] <= 109

Sample Input #00

1
3
1 2 3

Sample Output #00

12

Explanation
The given case will have 7 non-empty subsets whose XOR is given below
1 = 1
2 = 2
3 = 3
1^2 = 3
2^3 = 1
3^1 = 2
1^2^3 = 0
So sum of all such XORs is 12.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007
using namespace std;


int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        long long int num,ans=0;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>num;
            ans |=num;
        }
        ans %= MOD;
        n--;
        while(n--)
        {
            ans <<= 1;
            ans =ans%MOD;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

