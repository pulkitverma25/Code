/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/find-point

Given two points P and Q, output the symmetric point of point P about Q.

Input format:
The first line contains an integer T representing the number of testcases (T <= 15)
Each test case contains Px Py Qx Qy representing the (x,y) coordinates of P and Q, all of them being integers.

Constraints
1 <= T <= 15
-100 <= x, y <= 100

Output format
For each test case output x and y coordinates of the symmetric point

Sample input

1  
0 0 1 1

Sample output

2 2
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
    int t;
    cin>>t;
    
    while(t--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        
        cout<<(x2-x1)+x2<<" "<<(y2-y1)+y2<<endl;
    }
    return 0;
}

