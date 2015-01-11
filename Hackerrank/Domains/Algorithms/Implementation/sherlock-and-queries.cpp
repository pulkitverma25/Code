/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/sherlock-and-queries

Watson gives to Sherlock an array: A1,A2,⋯,AN. He also gives to Sherlock two other arrays: B1,B2,⋯,BM and C1,C2,⋯,CM.
Then Watson asks Sherlock to perform the following program:

for i = 1 to M do
    for j = 1 to N do
        if j % B[i] == 0 then
            A[j] = A[j] * C[i]
        endif
    end do
end do

Can you help Sherlock and tell him the resulting array A? You should print all the array elements modulo (109+7).

Input Format
The first line contains two integer numbers N and M. The next line contains N integers, the elements of array A. The next two lines contains M integers each, the elements of array B and C.

Output Format
Print N integers, the elements of array A after performing the program modulo (109+7).

Constraints
1≤N,M≤105
1≤B[i]≤N
1≤A[i],C[i]≤105

Sample Input

4 3
1 2 3 4
1 2 3
13 29 71

Sample Output

13 754 2769 1508    
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll a[100001],b[100001],c[100001],mul[100001];

int main() {
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<100001;i++)
        mul[i]=-1;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    for(int i=1;i<=m;i++)
    {
        if(mul[b[i]]==-1)
            mul[b[i]]=c[i];
        else
            mul[b[i]]=(mul[b[i]]*c[i])%MOD;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;(j*i)<=n;j++)
            if(mul[i]!=-1)
                a[j*i]=(a[j*i]*mul[i])%MOD;
    
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

