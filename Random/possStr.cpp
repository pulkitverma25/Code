/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
given set of characters find all possible strings with length k using set of characters

input: 
{a, b} 
arr_length = 3
output : 
aaa aab aba abb baa bab bba bbb
*/


#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;

string set;
void possComb(int k, string str)
{
	ll sz=set.size();
	if(k==0)
	{
		cout<<str<<endl;
		return;
	}
	for(ll i=0;i<sz;i++)
		possComb(k-1,str+set[i]);
	return;
}

int main()
{
	int z,n,k;
	scanf("arr_length=%d",&z);
	n=z;
	set="";
	char c;
	while(scanf(" %c ",&c) && c!='{');
	
	if(scanf("\"%[a-z]\"",&c))
		set+=c;
	for(ll i=1;i<n;i++)
	{
		scanf(",\"%[a-z]\"",&c);
		set+=c;
	}
	scanf("}\nk=%d",&k);
	
	possComb(k,"");


	return 0;
}
