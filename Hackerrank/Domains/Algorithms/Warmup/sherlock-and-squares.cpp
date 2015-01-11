/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/sherlock-and-squares

Watson gives two integers A & B to Sherlock and asks if he can count the number of square integers between A and B (both inclusive).

A square integer is an integer which is the square of any integer. For example, 1, 4, 9, 16 are some of the square integers as they are squares of 1, 2, 3, 4 respectively.

Input Format
First line contains T, the number of testcases. T test cases follow, each in a newline.
Each testcase contains two space separated integers denoting A and B.

Output Format
For each testcase, print the required answer in a new line.

Constraints
1 ≤ T ≤ 100
1 ≤ A ≤ B ≤ 109

Sample Input

2
3 9
17 24

Sample output

2
0

Explanation
Test Case #00: In range [3,9], 4 and 9 are the two square numbers.
Test Case #01: In range [17,24], there are no square numbers. 
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
        ll num1,num2;
        cin>>num1>>num2;
        
        if(((ll)(sqrt(num1)))==((ll)(sqrt(num2))))
        {
            ll temp1=(ll)(sqrt(num1));
            if(num1!=num2)
                cout<<"0"<<endl;
            else if(temp1*temp1==num1)
                cout<<"1"<<endl;     
            else
                cout<<"0"<<endl;
        }
        else
        {
            ll temp1=(ll)(sqrt(num1));
            ll temp2=(ll)(sqrt(num2));
            ll ans;
            if(temp1*temp1==num1)
                cout<<temp2-temp1+1<<endl;
            else
                cout<<temp2-temp1<<endl;            
        }
    }
    return 0;
}

