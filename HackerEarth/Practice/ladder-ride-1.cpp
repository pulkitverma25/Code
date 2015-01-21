/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.hackerearth.com/problem/algorithm/ladder-ride-1/

Harit wants to climb ladder having n steps but he want to climb only in step of 2 and 5. Now he felt boring repeating same thing again and again. So he discovered new way, now each time Harit wants to climb in step of k also. In other words he can use steps of 2, 5 or k to climb the ladder. So Harit want to calculate number of different ways to reach at cur step , where k and cur are integers . Although Harit is intelligent yet lazy so he wants your help to calculate number of ways. As number of ways could be too large so he wants you to output it modulo 1000000007 (10^9 + 7) .

Input :
First line consists two space separated integers t and n as number of test cases and total steps in ladder. Each of t lines contains two space separated integers cur and k .

Output :
For each test case output an integer calculated number of ways modulo (10^9 + 7) .

Constraints
1 <= t <= 100000
1 <= n <= 1000000
5 <= k <= 1000000000
cur <= n and sum of all cur such that ( cur >= k ) will not exceed 10000000 .
Sample Input (Plaintext Link)

3 10
6 7
6 6
9 7

Sample Output (Plaintext Link)

1
2
5

Explanation
In first test case there is only 1 way to reach at 6th step
i.e. taking step of (2,2,2) .
In second test case there are 2 ways to reach at 6th step
i.e. taking step of (2,2,2) or directly step of 6
in third test case there are 5 ways to reach at 9th step
i.e taking step (2,2,5) , (2,5,2) , (5,2,2) , (2,7) , (7,2) .
*/

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll f[1000001];
ll f2[1000001];

int main()
{
	ll t,n;
	scanf("%lld %lld ",&t,&n);

	f[0]=f[1]=f[3]=0;
	f[2]=f[4]=f[5]=1;
	
	for(ll i=6;i<=n;i++)
		f[i]=(f[i-2]+f[i-5])%MOD;
		
	for(ll z=0;z<t;z++)
	{
		ll curr,k;
		
		scanf("%lld %lld ",&curr,&k);
		
		if(k==5 || k>curr)
			printf("%lld\n",f[curr]);
		else
		{
			for(ll i=0;i<=k;i++)
				f2[i]=f[i];
				
			f2[k]=(f2[k]+1)%MOD;
			
			for(ll i=k+1;i<=curr;i++)
				f2[i]=(f2[i-k]+f2[i-2]+f2[i-5])%MOD;
							
			printf("%lld\n",f2[curr]);
		}
	}
	
	return 0;
}
