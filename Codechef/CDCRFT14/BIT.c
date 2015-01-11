/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
http://www.codechef.com/CDCRFT14/problems/BIT/

 Given N, if we write all numbers from 1 to N (both inclusive) in binary what is
the count of 1s I have written.
For example, if N=3,
I will write down:
1
10
11

Therefore, a total of 4 ones.
Input Format:

First line contains, T, the number of testcases. Each testcase consists of one integer per line denoting N.
Output Format:

Print the required answer.
Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000
Sample Input:

1
3

Sample Output:

4
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int t,num,totBits,i,j,k,noOfOne;
	
	scanf("%d\n",&t);
	
	while(t--)
	{
		scanf("%d\n",&num);
	
		totBits=(int)(log2(num+1));
		noOfOne=((pow(2,totBits))*totBits)/2;
		for(i=pow(2,totBits);i<=num;i++)
		{
			j=i;
			for(k=0;k<totBits+1;k++)
			{
				noOfOne+=(j&1);
				j>>=1;
			}
		}
		printf("%d\n",noOfOne);
	}
	return 0;
}
