/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/COOK52/problems/PETERSEN/

 The following graph G is called a Petersen graph and its vertices have been numbered from 0 to 9. Some letters have also been assigned to vertices of G, as can be seen from the following picture:

Let's consider a walk W in graph G, which consists of L vertices W1, W2, ..., WL, such that Wi is connected with Wi + 1 for 1 ≤ i < L. A string S of L letters 'A'-'E' is realized by walk W if the sequence of letters written along W is equal to S. Vertices can be visited multiple times while walking along W.

For example, S = 'ABBECCD' is realized by W = (0, 1, 6, 9, 7, 2, 3).

Your task is to determine whether there is a walk W which realizes a given string S in graph G, and if so, find the lexicographically least such walk.
Input

The first line of the input contains one integer T denoting the number of testcases to process.

The only line of each testcase contains one string S. It is guaranteed that S only consists of symbols 'A'-'E'.
Output

The output should contain exactly T lines, one line per each testcase in the order of their appearance. For each testcase, if there is no walk W which realizes S, then output -1. Otherwise, you should output the least lexicographical walk W which realizes S. Since all of the vertices are numbered from 0 to 9, then it can be encoded as a string consisting of symbols '0'-'9' (see the "Examples" section for more details).
Constraints

1 ≤ T ≤ 8;

1 ≤ |S| ≤ 100000(105).
Examples

Input:
2
AAB
AABE

Output:
501
-1
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

char pet[2][5][3]={
					{
						{'A','B','E'},{'A','B','C'},{'B','C','D'},{'C','D','E'},{'D','E','A'}
					},
					{
						{'A','C','D'},{'B','D','E'},{'A','C','E'},{'A','B','D'},{'B','C','E'}					
					}
				};
int arr[2][5][3]={
					{
						{5,1,4},{0,6,2},{1,7,3},{2,8,4},{3,9,0}
					},
					{
						{0,7,8},{1,8,9},{5,2,9},{5,6,3},{6,7,4}				
					}
				};
int main()
{
	int t;
	scanf(" %d ",&t);
	
	while(t--)
	{
		string s1="",s2="";
		char c,oldC;
		c=getchar();
		s1+=(c-'A'+'0');
		s2+=(c-'A'+5+'0');
		oldC=c;

		bool isO=true,isI=true;
		while( (c=getchar()) !=EOF)
		{
			if(c=='\n')
				break;
			int ind=oldC-'A';
			if(isO)
			{
				int i;
				for(i=0;i<3;i++)
					if(pet[0][ind][i]==c)
					{
						s1+=(arr[0][ind][i]+'0');
						break;
					}

				if(i==3)
					isO=false;
			}	
			if(isI)
			{
				int i;
				for(i=0;i<3;i++)
					if(pet[1][ind][i]==c)
					{
						s2+=(arr[1][ind][i]+'0');
						break;
					}

				if(i==3)
					isI=false;
			}	
			
			if(c==oldC)
			{
				bool temp=isO;
				isO=isI;
				isI=temp;
				string s=s1;
				s1=s2;
				s2=s;
			}
			oldC=c;

			
		}
		
		if(!isO && !isI)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(isO && isI && s1<s2)
			cout<<s1<<endl;
		else if(isO && isI)
			cout<<s2<<endl;
		
		if(isO && !isI)
			cout<<s1<<endl;
		if(!isO && isI)
			cout<<s2<<endl;		
	}
	
	return 0;
}

