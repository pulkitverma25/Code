/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/placement-preparation-2/challenges/2s-complement-1

One of the basics of Computer Science is knowing how numbers are represented in 2's complement.
In case you forgot, have a quick look here.
Given a 2's complement representation of an integer N you have to output the the 2's complement representation of its additive inverse (represented using the same number of bits as N).
Input Format

The first line contains the number of test cases T. Each of the next T lines contains the 2's complement representations.
Output Format

T lines, each denoting the 2's complement representation of the the additive inverse of the corresponding number.
Constraints

1 ≤ T ≤ 103
1 ≤ |N| ≤ 8192
- (2|N|-1 - 1 ) ≤ N ≤ (2|N|-1 - 1 )

where |N| denotes the number of bits in the given 2's complement representation.
Sample Input

4
0001
0110
1111
1010

Sample Output

1111
1010
0001
0110

Explanation

0001 is the 2's complement representation of 1, additive inverse of 1 is -1 as 1 + (-1) = 0
Now,the output will be 4-bit 2's complement representation (as input is 4 bit) of -1 which is 1111.
Similarly, 0110 the 2's complement representation of 6 and 4 bit 2's complement representation of -6 is 1010.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string num;
        cin>>num;
        bool isOne=false;
        int len=num.size();
        for(int i=len-1;i>=0;i--)
        {
            if(isOne==true)
            {
                if(num[i]=='1')
                    num[i]='0';
                else
                    num[i]='1';
            }
            if(isOne==false && num[i]=='1')
                isOne=true;
        }
        cout<<num<<endl;
    }
    return 0;
}
