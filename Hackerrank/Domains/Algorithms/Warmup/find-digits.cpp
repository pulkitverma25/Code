/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/find-digits

You are given an integer N. Find the digits in this number that exactly divide N(division that leaves 0 as remainder) and display their count. For N=24, there are 2 digits − 2 & 4. Both of these digits exactly divide 24. So our answer is 2.

Note

    If the same number is repeated twice at different positions, it should be counted twice, e.g., For N=122, 2 divides 122 exactly and occurs at ones' and tens' position. So for this case, our answer is 3.
    Division by 0 is undefined.

Input Format

The first line contains T (number of test cases) followed by T lines (each containing an integer N).

Constraints
1≤T≤15
0<N<1010

Output Format

For each test case, display the count of digits in N that exactly divide N in a separate line.

Sample Input

2
12
1012

Sample Output

2
3

Explanation

    2 digits in the number 12 divide the number exactly. Digits at tens' place, 1, divides 12 exactly in 12 parts, and digit at ones' place, 2 divides 12 equally in 6 parts.

    1 divides 1012 at two places and 2 divides it at one place. Divide by 0 is an undefined behaviour and it will not be counted.
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
        long long int num;
        cin>>num;
        long long int tempNum=num;
        int count=0;
        while(tempNum>0)
        {
            long long int temp=tempNum%10;
            if(temp!=0 && num%temp==0)
                count++;
            tempNum /=10;
        }
        cout<< count<<endl;
    }
    return 0;
}

