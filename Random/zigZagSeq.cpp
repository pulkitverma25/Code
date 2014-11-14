/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
Longest ZigZag subsequnce

A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
ex: 1,7,4,9,2,5 output = 6
*/

#include <cstdio>

using namespace std;
typedef long long int ll;

int main()
{
	ll num,prev=0;
	ll oldDiff=0,diff=0;
	ll count=0;
	if(scanf("{%lld",&num))
		count++;
	prev=num;
	if(scanf(",%lld",&num))
	{
		count++;
		diff=num-prev;
		oldDiff=diff;
		prev=num;
		while(scanf(",%lld",&num))
		{
			diff=num-prev;
			if(diff*oldDiff<0)
				count++;
			oldDiff=diff;
			prev=num;
		}
	}
	printf("%lld\n",count);
	
	return 0;
}
