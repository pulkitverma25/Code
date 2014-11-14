/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/
 
#include <stdlib.h>
#include <stdio.h>

void addElement(int* array, int newElement, int position, int* size, int* actualSize, int* currentSize)
{
	int i;
	if(position==*actualSize)
	{
		*size *=2;
		*actualSize *=2;
		i=*size;
		if((array=realloc(array, sizeof(int) * i))==NULL)
		{
			printf("\nERROR: Insufficient Memory\n");
			return;
		}
	}

	if(*currentSize>1)
	{
		for(i=*currentSize;i>=position-1;i--)
			array[i]=array[i-1];
	}	
	array[position-1]=newElement;
	*currentSize+=1;
	
	return;
}

void deleteElement(int* array, int position, int* size, int* actualSize,int* currentSize)
{
	int i;
	if(*currentSize<position || *currentSize==0)
	{
		printf("\nNot sufficient elements to delete");
		return;
	}

	for(i=position-1;i<*currentSize;i++)
		array[i]=array[i+1];
	
	*currentSize-=1;
	if(*actualSize==*size/4)
	{
		*size/=2;
		*actualSize/=2;
		i=*size;
		if((array=realloc(array, sizeof(int) * i))==NULL)
		{
			printf("\nERROR: Memory Issue\n");
			return;
		}
	}
	return;
}

int searchArray(int* array, int element, int currentSize)
{
	int i;
	for(i=0;i<currentSize;i++)
		if(array[i]==element)
			return i;

	return -1;	
}

void printArray(int* array, int currentSize)
{
	int i;
	if(currentSize!=0)
	{
		printf("\nArray:\n");
		for (i=0; i<currentSize; i++)
			printf("%d\t",array[i]);
	}
	else
		printf("\nEmpty Array.\n");
	return;
}
