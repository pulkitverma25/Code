/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/COOK50/problems/GRID/

Sherlock is stuck. There is a N X N grid in which some cells are empty (denoted by ‘.’), while some cells have rocks in them (denoted by ‘#’). Sherlock is on the South of the grid. He has to watch what is happening on the East of the grid. He can place a mirror at 45 degrees on an empty cell in the grid, so that he'll see what is happening on East side by reflection from the mirror.


But, if there's a rock in his line of sight, he won't be able to see what's happening on East side. For example, following image shows all possible cells in which he can place the mirror.

You have to tell Sherlock in how many possible cells he can place the mirror and see what's happening on East side.
Input

First line, T, the number of testcases. Each testcase will consist of N in one line. Next N lines each contain N characters.
Output

For each testcase, print the number of possible options where mirror can be placed to see on the East side.
Constraints

    1 ≤ T ≤ 10
    1 ≤ N ≤ 1000

 
Example

Input:
2
3
#..
#..
#..
3
#.#
#.#
#.#

Output:
6
0

Explanation

Example case 1. All places where rock are not there are valid positions.

Example case 2. No valid positions.



Note: Large input data. Use fast input/output.

Time limit for PYTH and PYTH 3.1.2 has been set 8s.
*/

#include <iostream>

using namespace std;

int posRowOK[1000];
int posColOK[1000];

void memClear()
{
	for(int i=0;i<1000;i++)
		posColOK[i]=posRowOK[i]=-1;
	return;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		memClear();
		int n;
		cin>>n;
		string row;
		int posCount=0;
		for(int i=0;i<n;i++)
		{
			cin>>row;
			for(int j=0;j<n;j++)		
				if(row[j]=='#')
				{
					posRowOK[i]=j;
					posColOK[j]=i;
				}				
		}

		for(int i=n-1;i>=0;i--)
			for(int j=n-1;j>=0;j--)
				if(i>=posColOK[j] && j>=posRowOK[i] && (i!=posColOK[j] || j!=posRowOK[i]))
						posCount++;
	
		cout<<posCount<<endl;
	}

	return 0;
}
