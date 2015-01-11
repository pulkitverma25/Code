/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/countingsort3

You will be given a list that contains both integers and strings. In this challenge you just care about the integers. For every value i from 0 to 99, can you output L, the number of elements that are less than or equal to i?

Input Format
n - the size of the list ar.

n lines follow, each containing an integer x, and a string, s.

Output Format
Output L for all numbers from 0 to 99 (inclusive).

Constraints
1 <= n <= 1000000
0 <= x < 100 , x ∈ ar

Sample Input

10
4 that
3 be
0 to
1 be
5 question
1 or
2 not
4 is
2 to
4 the

Sample Output

1 3 5 6 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 

Explanation
0 appears 1 time, so the 0th number is 1.
0 and 1 combined appear 3 times, so the next number is 3.
This continues for the rest of the list, until no more new numbers appear. 
*/

#include <bits/stdc++.h>

using namespace std;
int arr[100];

int main() {
    int n,m;
    cin>>n;
    m=n;
    memset(arr,0,sizeof(arr));
    
    while(m--)
    {
        int num;
        string str;
        cin>>num>>str;
        arr[num]++;
    }
    int sum=0;
    int count=0;
    for(int i=0;i<100;i++)
    {
        sum+=arr[i];
        if(arr[i]!=0)
        {
            count++;
            cout<<sum<<" ";
        }
    }
    for(int j=count;j<100;j++)
        cout<<sum<<" ";
    cout<<endl;
    
    return 0;
}
