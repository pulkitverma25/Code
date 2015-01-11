/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/infinitum-sep14/challenges/little-chammys-huge-donation

Little Ashish is doing internship at multiple places. Instead of giving parties to his friends he decided to donate candies to children. He likes solving puzzles and playing games. Hence he plays a small game. Suppose there are N children. The rules of the game are:

    The ith child gets i2 candies (1≤i≤N).

    The yth child cannot get a candy until and unless all the children before him (1≤i<y) gets candies according to rule number 1.

One of his jealous friends, Pipi, asks him "Given X (the number of candies) how many children will you be able to serve?". Little Ashish fears calculations and cannot solve this problem so he leaves this problem to the worthy programmers of the world. Help little Ashish in finding the solution.

Input Format
The first line contains T i.e. number of test cases.
T lines follow, each line containing an integer X.

Output Format
For each testcase, print the output that little Ashish wants in one line.

Constraints
1≤T≤10000
1≤X≤1016

Note: If the ith child doesn't get i2 number of candies then it's not counted as a successful donation

Sample Input

3
1
5
13

Sample Output

1  
2  
2  

Explanation

    For X=1. Only the 1st child can get the candy (i.e. 12 candy) and no other child.
    For X=5. Both the 1st(12 candies) and the 2nd(22 candies) children can get the candies.
    For X=13. Since the 3rd child will get only 8 candies following the rule it won't be counted as a successful donation. Only the 1st and the 2nd children can get 1 and 4 candies respectively.
*/
    
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

#define MAX 310725

ll noOfChild(ll num, ll start, ll end)
{
    ll i=(start+end)/2;
    ll temp=(i*(i+1)*(2*i+1))/6;
    ll temp2=((i+1)*(i+2)*(2*(i+1)+1))/6;
    if(temp<=num && temp2>num)
        return i;    
    else if(temp>=num && temp2>=num)
        return noOfChild(num,start,i);
    else if(temp<=num && temp2<=num)
        return noOfChild(num,i,end);

    return 1;
}

int main() 
{
    int t;
    cin>>t;
    ll maxNum=0,maxI=1;
    
    while(t--)
    {
        ll num,i=0,ans=0;
        cin>>num;
                
        cout<< noOfChild(num,0,MAX) <<endl;
    }
    return 0;
}

