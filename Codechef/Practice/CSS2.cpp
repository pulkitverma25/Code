/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/problems/CSS2

Cascading Style Sheets, or CSS is a style sheet language, most popularly known for styling web pages. Each object on a web page (like a picture, a paragraph, a table) can have various properties (like height, width, size, colour), and these properties can be set using CSS. Each of these objects has a unique identifier called id, using which CSS can identify the object and assign value to its property.

Due to hierarchical nature of the web page, often same property of an object gets assigned different values in different CSS statements. To decide what the final value will be, each statement has a priority assigned to it. The statement with the highest priority will be the one that sets the value of the property. If there are more than one statements with same priority, then the one which was executed last amongst those will set the value.

Given multiple CSS statements in the order they were executed, answer a few queries about the final values of certain objects
Input

First line contains two space-separated integers N and M, the number of CSS statements and the number of queries respectively.
Following N lines will each have 4 values id, attr, val, priority, which mean that a CSS statement tries to assign value val to the attribute named attr of the object id, and that the priority of this statement is equal to priority.
Each of the next M lines will contain two values id and attr, for which you have to print value of the attribute attr of object id. You can assume that there is a statement that assigns value to this attribute attr of object id.
Output

Print exactly M lines, ith line contains the answer to the ith query as described above.
Constraints

    1 ≤ value, priority ≤ 106, for all subtasks.
    For 20 points : 1 ≤ id, N, M, attr ≤ 103
    For 30 points : 1 ≤ N, M ≤ 103, 1 ≤ id, attr ≤ 106
    For 50 points : 1 ≤ N, M ≤ 105, 1 ≤ id, attr ≤ 106 

Example

Input:

3 1
22 1 200 2
22 1 300 2
22 1 100 1
22 1


Output:

300
*/

#include <cstdio>
#include <map>

using namespace std;
typedef long long int ll;

typedef pair<ll,ll> p;
int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	
	map<p,p> mMap;
	p p1, p2;	
	for(ll i=0;i<n;i++)
	{
		ll id,attr,val,prop;
		scanf("%lld %lld %lld %lld",&id,&attr,&val,&prop);
	
		p1=make_pair(id,attr);
		p2=make_pair(val,prop);
		if(!mMap.count(p1) || mMap[p1].second<=prop)
			mMap[p1]=p2;
	}

	for(ll i=0;i<m;i++)
	{
		ll id1,attr1;
		scanf("%lld %lld",&id1,&attr1);
		p temp=make_pair(id1,attr1);
		printf("%lld\n",mMap[temp].first);
	}

	return 0;
}
