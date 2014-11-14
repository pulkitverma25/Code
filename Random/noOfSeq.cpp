/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
There is a particular sequence only uses the numbers 1, 2, 3, 4 and no two adjacent numbers are the same.
Write a program that given n1 1s, n2 2s, n3 3s, n4 4s will output the number of such sequences using all these numbers.
Output your answer modulo 1000000007 (10^9 + 7).
*/

/*
Logic:
C[n1][n2][n3][n4]=C[n1][n2-1][n3][n4]
				  C[n1][n2][n3-1][n4]
				  C[n1][n2][n3][n4-1]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define TRUE 1
#define FALSE 0
#define MOD 1000000007

typedef long long int ll;

int dp[4][51][51][51][51];
int num[4];

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int findIndex(int val,int arr[])
{
	FOR(i,4)
		if(val==arr[i])
			return i;
	return 0;
}

long long int calcVal(int index, int arr[])
{
	int toContinue=FALSE;
	FOR(i,4)
		if(index!=i && arr[i]!=0)
		{
			toContinue=TRUE;
			break;
		}	
	if(!toContinue && arr[index]==0)
		return 1;	
	if(!toContinue && arr[index]>0)
		return 0;	

	if(dp[index][arr[0]][arr[1]][arr[2]][arr[3]]!=-1)
	{

		return dp[index][arr[0]][arr[1]][arr[2]][arr[3]];
	}	

	ll sum=0;
	FOR(i,4)
	{
		if(i==index || arr[i]==0)
			continue;
		int tmpArr[4];
		FOR(j,4)
			tmpArr[j]=arr[j];
		tmpArr[i]-=1;
		int val=tmpArr[i];		
		qsort (tmpArr, 4, sizeof(int), compare);
		
		sum=(sum+calcVal(findIndex(val,tmpArr),tmpArr))%MOD;
	}
	dp[index][arr[0]][arr[1]][arr[2]][arr[3]]=sum;

	return sum;
}


int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)	
	{
		memset(dp,-1,sizeof(dp));
		FOR(i,4)	
			scanf("%d",&num[i]);
		
		//qsort (num, 4, sizeof(int), compare);

		long long int sum=0;
		FOR(i,4)
		{
			if(num[i]==0)
				continue;
			int tmpArr[4];
			FOR(j,4)
				tmpArr[j]=num[j];
			tmpArr[i]-=1;
			int val=tmpArr[i];	
			qsort (tmpArr, 4, sizeof(int), compare);
			sum=(sum+calcVal(findIndex(val,tmpArr),tmpArr))%MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
