/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/insertion-sort

Sometimes, arrays may be too large for us to wait around for insertion sort to finish. Is there some other way we can calculate the number of times Insertion Sort shifts each elements when sorting an array?

If ki is the number of elements over which ith element of the array has to shift then total number of shift will be k1 + k2 + ... + kN.

Input:
The first line contains the number of test cases T. T test cases follow. The first line for each case contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]...,a[N].

Output:
Output T lines, containing the required answer for each test case.

Constraints:
1 <= T <= 5
1 <= N <= 100000
1 <= a[i] <= 1000000

Sample Input:

2  
5  
1 1 1 2 2  
5  
2 1 3 1 2

Sample Output:

0  
4   

Explanation
First test case is already sorted, therefore there's no need to shift any element. In second case, it will proceed in the following way.

Array: 2 1 3 1 2 -> 1 2 3 1 2 -> 1 1 2 3 2 -> 1 1 2 2 3
Moves:   -        1       -    2         -  1            = 4
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long int merge(long int arr[],long int left[],long int right[],long int l,long int r)
{
	long int i=0,j=0,count=0;
	while(i<l || j<r)
	{
		if(i==l)
		{
			arr[i+j]=right[j];
			j++;
		}
		else if(j==r)
		{
			arr[i+j]=left[i];
			i++;
		}
		else if(left[i]<=right[j])
		{
			arr[i+j]=left[i];
			i++;
		}
		else
		{
			arr[i+j]=right[j];
			count+=l-i;
			j++;
		}
	}
	 
	return count;
}
 
 
long int inversions(long int arr[],long int high)
{
	if(high<1)
		return 0;
	 
	long int mid=(high+1)/2;
	long int left[mid];
	long int right[high-mid+1];
	 
	long int i,j;
	for(i=0;i<mid;i++)
		left[i]=arr[i];
	 
	 
	for(i=high-mid,j=high;j>=mid;i--,j--)
		right[i]=arr[j];
	 
	return inversions(left,mid-1) + inversions(right,high-mid) + merge(arr,left,right,mid,high-mid+1);
 
}

int main() {
    int t;
    scanf("%d\n",&t);
    
    while(t--)
    {
        int n;
        scanf("%d\n",&n);
        
        long int *arr=(long int*)malloc(sizeof(long int)*n);
        for(int i=0;i<n;i++)
            scanf("%ld\n",&arr[i]);
        
        printf("%ld\n",inversions(arr,n-1));
        
        free(arr);
    }
    
    return 0;
}

