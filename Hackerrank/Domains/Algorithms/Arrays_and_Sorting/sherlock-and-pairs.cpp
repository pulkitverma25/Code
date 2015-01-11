/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/sherlock-and-pairs

Sherlock is given an array of N integers A0, A1 ... AN-1 by Watson. Now Watson asks Sherlock how many different pairs of indices i and j exist such that i is not equal to j but Ai is equal to Aj.

That is, Sherlock has to count total number of pairs of indices (i, j) where Ai = Aj AND i ≠ j.

Input Format
First line contains T, the number of testcases. T test case follows.
Each testcase consists of two lines, first line contains an integer N, size of array.
Next line contains N space separated integers.

Output Format
For each testcase, print the required answer in different line.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 106

Sample input

2
3
1 2 3
3
1 1 2

Sample output

0
2

Explanation
In the first testcase, no two pair of indices exist which satisfy the given property.
In second testcase as A[0] = A[1] = 1, the pairs of indices (0,1) and (1,0) satisfy the given property. 
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll arr[1000000];

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        ll num;
        cin>>num;
        
        for(int i=0;i<num;i++)
        {
            ll temp;
            cin>>temp;
            arr[temp-1]++;
        }
    
        ll count=0;

        for(int i=0;i<1000000;i++)
            count= count+(arr[i]*(arr[i]-1));
            
        cout<<count<<endl;   
    }
        
    return 0;
}

