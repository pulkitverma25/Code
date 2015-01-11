/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/placement-preparation-2/challenges/column-name

MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc.
In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

Given a column number C, find its corresponding Excel column name.
Input Format

The first line contains T (number of test cases) followed by T lines each denoting the column number.
Output Format

For each test case print the column name.(All Capital)
Constraints

1 ≤ T ≤ 2 * 105
1 ≤ C ≤ 109
Sample Input

3
1
26
27

Sample Output

A
Z
AA
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long int ull;

int main() 
{
    int t;
    cin>>t;
    string s;
    
    while(t--)
    {
        ull num;
        cin>>num;
        string ans;
        
        while(num>0)
        {
            num--;
            ull temp=(num)%26;
            num /= 26;
            char t=(temp)+'A';
            ans.append(1,t);
        }
        ull len=ans.size();
        
        for(int i=len-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}

