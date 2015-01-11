/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/fun-2-0/challenges/costliest-path

Let's consider a lower triangular matrix (a matrix in wich a number appears in the first row, two numbers appear in the second row, three in third row and so on). Each cell of the matrix has a value.

Write a code to compute the largest of the sums of numbers that appear on the path starting from the top towards the base, but here you can move either directly below or below at one place to the right(eg. if you are at location[i][j] then you can move on [i+1][j] or [i+1][j+1] ).

Input

The first line contain a single integer T <= 1000 the number of test cases. Then T test cases follow. Each test case starts with the number of lines which is followed by their content.

Output

For each test case write the determined value in a separate line.

Constraints

The number of rows is strictly positive, but less than 100. All numbers are positive integers between 0 and 1000.

Example

Input

2

3

1

2 1

1 2 3

4

1

1 2

4 1 2

2 3 1 1 

Output

5

9
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

ll arr[100][100];
ll meomize[100][100];

void res()
{
    for(ll i=0;i<100;i++)
        for(ll j=0;j<100;j++)
            arr[i][j]=meomize[i][j]=0;
    return;
}

int main() {
    ll t;  
    cin>>t;
    
    while(t--)
    {
        res();
        
        ll n;
        cin>>n;
        
        for(ll i=0;i<n;i++)
            for(ll j=0;j<=i;j++)
                cin>>arr[i][j];
        for(ll i=0;i<n;i++) 
            meomize[i][0]=meomize[i-1][0]+arr[i][0];
            
        ll maxVal=meomize[n-1][0];  
        for(ll i=1;i<n;i++)
            for(ll j=1;j<=i;j++)
            {
                meomize[i][j]=arr[i][j]+max(meomize[i-1][j-1],meomize[i-1][j]);
                if(i==n-1 && meomize[i][j]>maxVal)
                    maxVal=meomize[i][j];
            }
        
        cout<<maxVal<<endl;
    }
 
    
    
    
    return 0;
}

