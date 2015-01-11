/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/sherlock-and-gcd

Sherlock is stuck. He has an array A1,A2,⋯,AN. He wants to know if there exists a subset, B={Ai1,Ai2,…,Aik} where 1≤i1<i2<…<ik≤N, of this array which follows the property

    B is non-empty subset.
    There exists no integer x(x>1) which divides all elements of B. Note that x may or may not be an element of A.

Input Format
First line contains T, the number of testcases. Each testcase consists of N in one line. The next line contains N integers denoting the array A.

Output
Print YES or NO, if there exists any such subset or not, respectively.

Constraints
1≤T≤10
1≤N≤100
1≤Ai≤105 ∀1≤i≤N

Sample input

2
3
1 2 3
2
2 4

Sample output

YES
NO

Explanation
In first testcase, S={1},S={1,2},S={1,3},S={2,3} and S={1,2,3} are all the possible subsets which satisfy the given condition.
In second testcase, no non-empty subset exists which satisfies the given condition. 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int num1, int num2)
{
    if(num2==0) 
    	return num1;
    return gcd(num2,num1%num2);
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,hcf=0,num;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>num;
            hcf=gcd(hcf,num);
        }
        if(hcf==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}

