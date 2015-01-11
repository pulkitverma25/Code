/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
http://www.codechef.com/SEPT14/problems/ROTATION/

 You are given an array A of N integers. You are to fulfill M queries. Each query has one of the following three types:

    C d : Rotate the array A clockwise by d units.
    A d : Rotate the array A anticlockwise by d units.
    R d : Query for the value of the element, currently being the d-th in the array A.

Input

The first line contains two numbers - N and M respectively.

The next line contains N space separated Integers, denoting the array A.

Each of the following M lines contains a query in the one of the forms described above.
Output

For each query of type R output the answer on a separate line.
Constraints

    1 ≤ N ≤ 100000
    1 ≤ M ≤ 100000
    1 ≤ d ≤ N, in all the queries
    1 ≤ elements of A ≤ 1000000
    The array A and the queries of the type R are 1-based. 

 
Example

Input:
5 5
5 4 3 3 9
R 1
C 4
R 5
A 3
R 2
Output:
5
3
3

Explanation

The initial array : 5 4 3 3 9

The answer for R 1 : 5

The array after C 4 : 9 5 4 3 3

The answer for R 5 : 3

The array after A 3 : 4 3 3 9 5

The answer for R 2 : 3 
*/

#include <stdio.h>
#include <stdlib.h>

long int array[100000];

int main()
{
	int i,n,m,num,start,point;
	char c;

	scanf("%d %d\n",&n,&m);
	
	point=start=1;

	for(i=0; i<n;i++)
		scanf("%ld ",&array[i]);


	while(m--)
	{		
		scanf("%c %d\n",&c,&num);
		
		if (c=='C')
			start+=num;
		else if (c=='A')	
			start-=num;
		else if (c=='R')
			point=start+num-2;
	
		if (c=='A' || c=='A')
		{
			while(start <1 || start >n)
			{
				if(start <1)
					start+=(((start/n)+1)*n);
				else if (start >n)
					start-=((start/n)*n);
			}
		}
		else if (c=='R')
		{
			while (point <0 || point >n-1)
			{
				if(point <0)
					point+=(((point/n)+1)*n);
				else if (point >n-1)
					point-=((point/n)*n);
			}
			printf("%ld\n",array[point]);
		}

	}


	return 0;
}
