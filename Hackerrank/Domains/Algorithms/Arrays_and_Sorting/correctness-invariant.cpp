/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
https://www.hackerrank.com/challenges/correctness-invariant

In the InsertionSort code below, there is an error. Can you fix it? Print the array only once, when it is fully sorted.

Details
The Input format and the constraints are the same as the previous challenges and are presented below.

Input Format
There will be two lines of input:

    s - the size of the array
    ar - the list of numbers that makes up the array

Output Format
Output the numbers in order, space-separated.

Constraints
1<=s<=1000
-1500<=x<= 1500 , x ∈ ar

Sample Input

6
1 4 3 5 6 2

Sample Output

1 2 3 4 5 6 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int ar_size, int *  ar) {    
    int i,j;
    int value;
    for(i=1;i<ar_size;i++)
    {
        value=ar[i];
        j=i-1;
        while(j>=0 && value<ar[j])
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=value;        
    }
    for(j=0;j<ar_size;j++)
    {
        printf("%d",ar[j]);
        printf(" ");
    }
}

int main(void) 
{
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)  
		scanf("%d", &_ar[_ar_i]); 

	insertionSort(_ar_size, _ar);
   
   return 0;
}

