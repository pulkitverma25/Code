/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/two-arrays

You are given two integer arrays, A and B, each containing N integers. The size of the array is less than or equal to 1000. You are free to permute the order of the elements in the arrays.

Now here's the real question: Is there an permutation A', B' possible of A and B, such that, A'i+B'i ≥ K for all i, where A'i denotes the ith element in the array A' and B'i denotes ith element in the array B'.


Input Format
The first line contains an integer, T, the number of test-cases. T test cases follow. Each test case has the following format:

The first line contains two integers, N and K. The second line contains N space separated integers, denoting array A. The third line describes array B in a same format.

Output Format
For each test case, if such an arrangement exists, output "YES", otherwise "NO" (without quotes).


Constraints
1 <= T <= 10
1 <= N <= 1000
1 <= K <= 109
0 <= Ai, Bi ≤ 109


Sample Input

2
3 10
2 1 3
7 8 9
4 5
1 2 2 1
3 3 3 4


Sample Output

YES
NO

Explanation

The first input has 3 elements in Array A and Array B, we see that the one of the arrangements, 3 2 1 and 7 8 9 has each pair of elements (3+7, 2 + 8 and 9 + 1) summing upto 10 and hence the answer is "YES".

The second input has array B with three 3s. So, we need at least three numbers in A that are greater than 1. As this is not the case, the answer is "NO". 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;
vector <int >arr1(1000),arr2(1000);

bool compare1(const int a, const int b)
{
    return a<b;    
}

bool compare2(const int a, const int b)
{
    return a>b;    
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        ll k;
        cin>>n>>k;
        
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        
        sort(arr1.begin(),arr1.begin()+n,compare1);
        sort(arr2.begin(),arr2.begin()+n,compare2);
        
        bool isOk=true;
        for(int i=0;i<n;i++)
            if(arr1[i]+arr2[i]<k)
            {
                isOk=false;
                break;
            }
            
        if(isOk)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}

