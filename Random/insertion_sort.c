/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Implementation of insertion sort
*/

#include <stdio.h>

int main ()
{
	int arr[10],i;
	
	printf("\nEnter the elements of the array \n");
	for(i=0; i<10; i++)
		scanf("%d", &arr[i]);
	
	insertsort(arr,10);

	printf("\nThe sorted array is: \n");
	for(i=0; i<10; i++)
		printf("%d \n", arr[i]);

	return 0;
}
