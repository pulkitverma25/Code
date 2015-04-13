/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/zenhacks/challenges/funny-string

Suppose you have a string S which has length N and is indexed from 0 to N−1. String R is the reverse of the string S. The string S is funny if the condition |Si−Si−1|=|Ri−Ri−1| is true for every i from 1 to N−1.

(Note: Given a string str, stri denotes the ascii value of the ith character (0-indexed) of str. |x| denotes the absolute value of an integer x)

Input Format

First line of the input will contain an integer T. T testcases follow. Each of the next T lines contains one string S.

Constraints

    1<=T<=10
    1<=length of S<=10000

Output Format

For each string, print Funny or Not Funny in separate lines.

Sample Input

2
acxz
bcxz

Sample Output

Funny
Not Funny

Explanation

Consider the 1st testcase acxz

here

|c-a| = |x-z| = 2
|x-c| = |c-x| = 21
|z-x| = |a-c| = 2

Hence Funny.

Consider the 2st testcase bcxz

here

|c-b| != |x-z|

Hence Not Funny
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
    cin>>t;
    
    string s;
    
    while(t--)
    {
        cin>>s;
        
        ll len=s.size();
        ll tLen=len>>1;
        bool isDone=false;
        for(ll i=1;i<=tLen;i++)
        {
            if(abs(s[i]-s[i-1])!=abs(s[len-i]-s[len-i-1]))
            {
                cout<<"Not Funny"<<endl;
                isDone=true;
                break;
            }
        }
        if(!isDone)
            cout<<"Funny"<<endl;
    }
    
    return 0;
}
