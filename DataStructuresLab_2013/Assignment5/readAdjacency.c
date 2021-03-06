/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

//Assignment3

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "readAdjacency.h"




int getNodeCount(char *inputFile) //Returns the number of vertex
{
	FILE *fp;
	char str[50];
	int count=0;
	if ((fp=fopen(inputFile,"r"))==NULL)
	{
		printf("\nError opening file\n");
		exit(-1);
	}
	while((fgets(str,49,fp))!=NULL)
		count++;
	fclose(fp);
	
	return count-1;
}

LINKED_LIST* readAdjacencyList(char *inputFile,LINKED_LIST *vertex,int count)
//Reads the adjacency list
{
	char exc; //Can accomodate graph with 9999 nodes
	int nodeNum=0;
	LINKED_LIST lastNode;
	int listNumber;

	FILE *fp2;
	if((fp2=fopen(inputFile,"r"))==NULL)
	{
		printf("\nError Opening File");
		exit(-1);
	}

	vertex=(LINKED_LIST*)malloc(count*sizeof(LINKED_LIST)); //Allocates the memory to pointer array storing the adjacency list

	int k;
	for(k=0;k<count;k++) //Allocates memory to each list corresponding to a single vertex
	{
		vertex[k]=getNode();
		vertex[k]->next=NULL;
	}

	while((fscanf(fp2,"%d ",&nodeNum))>0) //Reads the file character by character
	{
		listNumber=nodeNum-1; 
		lastNode=vertex[listNumber]; //store the list in corresponding position in array

		int tempNodeNum,tempNodeWeight;
		do
		{		
			fscanf(fp2,"%d,%d%c",&tempNodeNum,&tempNodeWeight,&exc);
			LINKED_LIST tempNode; //Create a new node when space encountered
			tempNode=getNode();
			tempNode->key=tempNodeNum;
			tempNode->weight=tempNodeWeight;
			tempNode->next=NULL;
			lastNode->next=tempNode;
			lastNode=tempNode;

			if(feof(fp2) || exc=='\n')
				break;

		}while(1);
	}

	fclose(fp2);

	return vertex;	

}

void printList(LINKED_LIST head) //Prints the linked list in adjacency list pattern
{
	if(isListEmpty(head))
		return;
	else{
	LINKED_LIST tempNode=getNode();
	tempNode=head->next;	
	while(tempNode != NULL)
	{
		printf("->(%d,%d)",tempNode->key,tempNode->weight);
		tempNode=tempNode->next;
	}
	printf("\n\n");
	}
	return;
}

void printAdjacencyList(LINKED_LIST *vertex, int count) //Calls the print function for each list in array of adjacency list
{
	int k;
	printf("\nAdjacency List:\n");
	for (k=0;k<count;k++)
	{
		printf("%d",k+1);		
		printList(vertex[k]);
	}
}







