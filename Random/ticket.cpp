/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
There are “n” ticket windows in the railway station. ith window has ai tickets available. Price of a ticket is equal to the number of tickets remaining in that window at that time. When “m” tickets have been sold, what’s the maximum amount of money the railway station can earn?
exa. n=2, m=4
in 2 window available tickets are : 2 , 5
from 2nd wicket sold 4 tickets so 5+4+3+2=14.
*/

#include <queue>
#include <cstdio>
#include <functional>
#include <algorithm>
#define FOR(i,n) for(ll i=0;i<n;i++)

using namespace std;
typedef long long int ll;
int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{

		ll n,m,num,sum=0,count=0;
		scanf("%lld %lld",&n,&m);
	
		vector <ll> v,vDiff;
	
		FOR(i,n)
			scanf("%lld",&num), v.push_back(num);
		
		sort(v.begin(),v.end(),greater<ll>());
	
		FOR(i,n)
		{
			if(i==n-1) 
				v.push_back(v[i]);
			else if(v[i]==v[i+1])
				continue;

			if(m<=0)
				break;
		
			if(i==n-1 || v[i]-v[i+1]>=m/(i+1))
			{
				/*
				The Logic: The last time loop runs, m will become 0 after this block
	
				ll firstVal=v[i];
				ll valCount=m/(i+1);
				ll lastVal= firstVal-(valCount-1);
				ll newSum=(firstVal+lastVal)*valCount/2;	
				ll remVal=m%(i+1);
				ll remSum=(lastVal-1)*remVal;	
			
				sum+=newSum*(i+1)+remSum;
				*/
				sum+=((v[i]+(v[i]-((m/(i+1))-1)))*(m/(i+1))/2)*(i+1) + (((v[i]-((m/(i+1))-1))-1)*(m%(i+1)));
				m-=((m/(i+1))*(i+1) + (m%(i+1)));
			}
			else
			{
				/*
				The Logic: The for loop is not over yet

				ll firstVal=v[i];
				ll lastVal=v[i+1]+1;
				ll valCount=v[i]-v[i+1];	

				sum+=(firstVal+lastVal)*(i+1)*valCount/2;				
				*/
				sum+=(v[i]+v[i+1]+1)*(i+1)*(v[i]-v[i+1])/2;		
				m-=((i+1)*(v[i]-v[i+1]));
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
