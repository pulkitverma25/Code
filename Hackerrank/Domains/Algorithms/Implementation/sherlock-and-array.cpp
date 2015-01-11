/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/sherlock-and-array

Watson gives an array A1,A2...AN to Sherlock. Then he asks him to find if there exists an element in the array, such that, the sum of elements on its left is equal to the sum of elements on its right. If there are no elements to left/right, then sum is considered to be zero.
Formally, find an i, such that, A1+A2...Ai-1 = Ai+1+Ai+2...AN.

Input Format
The first line contains T, the number of test cases. For each test case, the first line contains N, the number of elements in the array A. The second line for each testcase contains N space separated integers, denoting the array A.

Output Format
For each test case, print YES if there exists an element in the array, such that, the sum of elements on its left is equal to the sum of elements on its right, else print NO.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 2*104 for 1 ≤ i ≤ N

Sample Input

2
3
1 2 3
4
1 2 3 3

Sample Output

NO
YES

Explanation
For test case 1, no such index exists.
For test case 2, A[1]+A[2]=A[4], therefore index 3 satisfies.
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
        ll n;
        cin>>n;
        
        ll sum =0;
        vector<ll>arr(n);
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        ll sumL=0;
        ll sumR=sum;
        bool isFound=false;
        for(int i=0;i<n;i++)
        {
            sumR-=arr[i];
            if(sumL==sumR)
            {
                isFound=true;
                break;
            }
            sumL+=arr[i];
        }
        if(isFound)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
        
    }
    return 0;
}

