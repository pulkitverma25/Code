/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/DEC14/problems/XORSUB/

You have an array of integers A1, A2, ..., AN. The function F(P), where P is a subset of A, is defined as the XOR (represented by the symbol ⊕) of all the integers present in the subset. If P is empty, then F(P)=0.

Given an integer K, what is the maximum value of K ⊕ F(P), over all possible subsets P of A?
Input

The first line contains T, the number of test cases. Each test case consists of N and K in one line, followed by the array A in the next line.
Output

For each test case, print the required answer in one line.
Constraints

    1 ≤ T ≤ 10
    1 ≤ K, Ai ≤ 1000
    Subtask 1 (30 points):1 ≤ N ≤ 20
    Subtask 2 (70 points):1 ≤ N ≤ 1000

Example

Input:
1
3 4
1 2 3

Output:
7

Explanation

Considering all subsets:

F({}) = 0 ⇒ 4 ⊕ 0 = 4

F({1}) = 1 ⇒ 4 ⊕ 1 = 5

F({1,2}) = 3 ⇒ 4 ⊕ 3 = 7

F({1,3}) = 2 ⇒ 4 ⊕ 2 = 6

F({1,2,3}) = 0 ⇒ 4 ⊕ 0 = 4

F({2}) = 2 ⇒ 4 ⊕ 2 = 6

F({2,3}) = 1 ⇒ 4 ⊕ 1 = 5

F({3}) = 3 ⇒ 4 ⊕ 3 = 7

Therefore, the answer is 7. 
*/

#include <bits/stdc++.h>

using namespace std;
int dp[1025][1000];
int arr[1000];
int maxSubsetXor(int n, int xorRem, int maxVal)
{
	//cout<<"n= "<<n<<" xorRem= "<<xorRem<<" maxVal= "<<maxVal<<endl;
   if (n == -1)
     return max(xorRem,maxVal);
     
	if( dp[xorRem][n] !=-1 )
		return dp[xorRem][n];
   return dp[xorRem][n]= max(max(maxSubsetXor(n-1, xorRem, maxVal),maxSubsetXor(n-1, xorRem ^ (arr[n]), maxVal)),max(maxVal,xorRem));
}

int main()
{
	int t;
	scanf("%d ",&t);
	
	while(t--)
	{

		int n,m,k,ans=0;
		scanf("%d %d",&n,&m);
		memset(dp,-1,sizeof(dp));
		memset(arr,0,sizeof(arr));
		
		for(int i=0;i<n;i++)
			scanf("%d ",&arr[i]);

		printf("%d\n",maxSubsetXor(n-1,m,m));
	}


	return 0;
}

