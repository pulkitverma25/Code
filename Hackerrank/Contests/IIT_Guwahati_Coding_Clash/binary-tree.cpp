/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/contests/iit-guwahati-coding-clash/challenges/binary-tree-

Given an infinite complete binary tree . The root is Numbered 1. Every node n has the left child as 2*n and the 2*n+1 as the right child . Given two nodes x and y find the distance between the nodes.

INPUT:-

First Line is the number of testcases t.

Each next Lines have two space separated integers x and y.

OUTPUT:-

A single line denoting the distance between the nodes.

CONSTRAINTS:-

1<=T<=200000

1<= x,y <= 10^9
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll t;
	scanf("%lld\n",&t);
	
	while(t--)
	{
		ll n1,n2;
		scanf("%lld %lld",&n1,&n2);
		ll ctr = 0;
		while(n1^n2)
		{
			if(n1>n2)
				n1=n1>>1;
			else
				n2=n2>>1;
			ctr++;
		}
		
		printf("%lld\n",ctr);
	}
	return 0;	
}
