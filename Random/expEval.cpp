/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Evaluate Expression=>4 operators in order of precedence: (%,*,+,-); associativity is left to right. Ex: 2+43%4*3=11
*/

#include <cstdio>
#include <stack>
#include <cctype>
#include <map>

using namespace std;
typedef long long int ll;

stack<ll>numStack;
stack <char> opStack;
map<char,int>mMap;
	
void handleStack()
{
	ll n2=numStack.top();
	numStack.pop();

	ll n1=numStack.top();
	numStack.pop();

	char temp=opStack.top();
	opStack.pop();

	if(temp=='%')
		numStack.push(n1%n2);
	else if(temp=='+')
		numStack.push(n1+n2);
	else if(temp=='-')
		numStack.push(n1-n2);
	else if(temp=='*')
		numStack.push(n1*n2);

	return;		
}

int main()
{
	mMap.insert ( pair<char,int>('-',1) );
	mMap.insert ( pair<char,int>('+',2) );
	mMap.insert ( pair<char,int>('*',3) );
	mMap.insert ( pair<char,int>('%',4) );
	
	bool insideNum=false;
	ll n1,n2,num=0;
	char c;
	while((c=getchar()) != EOF)
	{
		if(!insideNum && isdigit(c))
		{
			num=c-'0';
			insideNum=true;
		}
		else if(insideNum && isdigit(c))
		{
			num*=10;
			num+=c-'0';
		}
		else if(insideNum && !isdigit(c))
		{
			numStack.push(num);
			insideNum=false;
			num=0;
			if(c=='%' || c=='+' || c=='*' || c=='-')
			{
				if(!opStack.empty() && mMap[opStack.top()]>=mMap[c])
				{
					while(!opStack.empty() && mMap[opStack.top()]>=mMap[c])
						handleStack();
				}
				opStack.push(c);
			}
		}

	}
	
	if(insideNum)
		numStack.push(num);
	
	while(!opStack.empty())
		handleStack();
		
	printf("%lld\n",numStack.top());

	return 0;
}
