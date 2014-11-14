/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Generate all subsequences of a string and print them in sorted order.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long int ll;
using namespace std;
vector<string> v;
int loc[26];


void generateSubS(string s)
{
	string str="";
	ll n=s.size();
	for(ll i=0;i<n;i++)
	{
		str=s[i];
		v.push_back(str);
		for(ll j=1;j<n-i;j++)
		{	str=s[i];
			for(ll k=0;k<n-i;k++)
				str+=s[i+k+j];
			v.push_back(str);
		}
	}
}


int main()
{
	string s;
	cin>>s;
	memset(loc,0,sizeof(loc));

	ll len=s.size();
	for(ll i=0;i<len;i++)
	{
		loc[s[i]-'a']=i;
	}

	generateSubS(s);
	sort(v.begin(),v.end());
	ll l=v.size();

	for(ll i=0;i<l;i++)
		cout<<v[i]<<endl;	

	return 0;	
}
