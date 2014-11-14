/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
You are given a phone keypad like following diagram, where each character corresponds to a digit mentioned in the same box.
You are given n strings and you have to find their decimal representation. You have to print the string and corresponding decimal representation in descending order.
Like if you are given “amazon” then its corresponding decimal notation will be 262966.
If more than one strings have same decimal notation then you have to print them in the order in which input is given.
(Given that given string consists of lower case alphabets only.)

Test Case 1:
5
Amazon
Microsoft
Facebook
Aa
Bb

Output:
642767638  microsoft
32232665  facebook
262966  amazon
22 aa
22 bb 
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
typedef long long int ll;

struct dataS
{
	string s;
	string d;
	ll len;
};

typedef struct dataS ds;

bool compare(ds a, ds b)
{
	if(a.len==b.len)
		return a.d>b.d;
	return a.len>b.len;
}

string sToDigit(string s, ll siz)
{
	string arr[26]={"2","2","2","3","3","3","4","4","4","5","5","5","6","6","6","7","7","7","7","8","8","8","9","9","9","9"};
	string str="";
	for(ll i=0;i<siz;i++)
		str+=arr[tolower(s[i])-'a'];
		
	return str;
}

int main()
{
	ll n;
	scanf("%lld",&n);
	
	vector<ds> v(n);
	
	for(ll i=0;i<n;i++)
	{
		cin>>v[i].s;
		v[i].len=v[i].s.size();
		v[i].d=sToDigit(v[i].s,v[i].len);
	}
	
	stable_sort(v.begin(),v.end(),compare);

	for(ll i=0;i<n;i++)
		printf("%s %s\n",v[i].d.c_str(),v[i].s.c_str());
	return 0;
}

