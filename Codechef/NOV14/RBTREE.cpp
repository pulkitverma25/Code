/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/NOV14/problems/RBTREE/

Chef likes trees a lot. Today he has an infinte full binary tree (each node has exactly two childs) with special properties.
Chef's tree has the following special properties :

    Each node of the tree is either colored red or black.
    Root of the tree is black intially.
    Both childs of a red colored node are black and both childs of a black colored node are red.

The root of the tree is labelled as 1. For a node labelled v, it's left child is labelled as 2*v and it's right child is labelled as 2*v+1.

Chef wants to fulfill Q queries on this tree. Each query belongs to any of the following three types:

    Qi Change color of all red colored nodes to black and all black colored nodes to red.
    Qb x y Count the number of black colored nodes on the path from node x to node y (both inclusive).
    Qr x y Count the number of red colored nodes on the path from node x to node y (both inclusive).

Help chef accomplishing this task.


Input

First line of the input contains an integer Q denoting the number of queries. Next Q lines of the input contain Q queries (one per line). Each query belongs to one of the three types mentioned above.


Output

For each query of type Qb or Qr, print the required answer.


Constraints

    1<=Q<=105


    1<=x,y<=109



Sample Input

5
Qb 4 5
Qr 4 5
Qi
Qb 4 5
Qr 4 5


Sample Output

2
1
1
2


Explanation

With the initial configuration of the tree, Path from node 4 to node 5 is 4->2->5 and color of nodes on the path is B->R->B.

    Number of black nodes are 2.
    Number of red nodes are 1.

After Query Qi, New configuration of the path from node 4 to node 5 is R->B->R.

    Number of black nodes are 1.
    Number of red nodes are 2.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ll q;
	scanf("%lld\n",&q);
	bool isBlack=true;
	while(q--)
	{
		char c;
		scanf(" Q%c",&c);
		if(c=='i')
		{
			isBlack=(!isBlack);
			continue;
		}
		
		ll n1,n2;
		scanf("%lld %lld ",&n1,&n2);
		ll ctr = 0;
		while(n1^n2)
		{
			ll mx=max(n1,n2);
			bool isRoot=!(((ll)(log2(mx))) & 1);
			if((isBlack == isRoot) && c=='b')
				ctr++;
			else if((isBlack!=isRoot) && c=='r')
				ctr++;
			
			if(n1>n2)
				n1=n1>>1;
			else
				n2=n2>>1;
		}
		
		bool isRoot=!(((ll)(log2(n1))) & 1);
		if((isBlack == isRoot) && c=='b')
				ctr++;
		else if((isBlack!=isRoot) && c=='r')
				ctr++;
				
		printf("%lld\n",ctr);
	}
	return 0;	
}
