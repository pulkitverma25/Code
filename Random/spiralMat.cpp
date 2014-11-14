/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
Given a 2D array, print it in spiral form. See the following examples.

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/

#include <cstdio>

using namespace std;
typedef long long int ll;

ll mat[1000][1000];

int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			scanf("%lld",&mat[i][j]);

	ll flag=0,count=0;
	ll eleC=n*m;
	ll rMin=0,cMin=0,rMax=n-1,cMax=m-1;
	while(count<eleC)
	{
		if(flag==0)
		{
			for(ll i=cMin;i<=cMax;i++,count++)
				printf("%lld ",mat[rMin][i]);
			rMin++;
			flag=1;
		}
		else if(flag==1)
		{
			for(ll i=rMin;i<=rMax;i++,count++)
				printf("%lld ",mat[i][cMax]);
			cMax--;
			flag=2;
		}
		else if(flag==2)
		{
			for(ll i=cMax;i>=cMin;i--,count++)
				printf("%lld ",mat[rMax][i]);
			rMax--;
			flag=3;
		}
		else if(flag==3)
		{
			for(ll i=rMax;i>=rMin;i--,count++)
				printf("%lld ",mat[i][cMin]);
			cMin++;
			flag=0;
		}
	}
	printf("\n");

	return 0;
}

