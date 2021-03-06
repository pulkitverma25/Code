/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

int count=0;

void insertElement(char* name2, int priority, HEAP priorityQueueRoot)
{
	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode->priority=priority;
	strcpy(tempNode->name,name2);
	tempNode->leftChild=NULL;
	tempNode->rightChild=NULL;
	tempNode->parent=NULL;
	count++;
	addElementToHeap(priorityQueueRoot,tempNode,count);
	printf("\nElement inserted");
	return;
}

void deleteMax(HEAP priorityQueueRoot)
{
	printf("\nElement deleted");
	if(count==0)
	{
		printf("\nPriority Queue already empty!!\n");
		return;
	}
	else if(count==1)
	{
		count--;
		priorityQueueRoot->name[0]='\0';
		priorityQueueRoot->rightChild=NULL;
		priorityQueueRoot->leftChild=NULL;
		priorityQueueRoot->rightChild=NULL;
		return;
	}
	int poppedNumber,pushNumber;
	STACK myStackHead;
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;

	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode=priorityQueueRoot;

	int temp=count;
	while(temp!=0)
	{
		pushNumber=temp%2;
		temp/=2;
		push(myStackHead,pushNumber);
	}

	poppedNumber=pop(myStackHead);
	if(poppedNumber==-1)
		return;
		while(1)
		{
			poppedNumber=pop(myStackHead);
			if(poppedNumber==-1)
			{
				swapData(tempNode,priorityQueueRoot);
				if(temp==0)
					tempNode->parent->leftChild=NULL;
				else if(temp==1)
					tempNode->parent->rightChild=NULL;
				heapifyDown(priorityQueueRoot);
				count--;
				freeHeapNode(tempNode);
				break;
			}			
			else if(poppedNumber==0)
			{
				tempNode=tempNode->leftChild;
				temp=poppedNumber;
			}
			else if(poppedNumber==1)
			{
				tempNode=tempNode->rightChild;
				temp=poppedNumber;
			}
		}

	return;
}

void getMax(HEAP priorityQueueRoot)
{
	if(count==0)
	{
		printf("\nPriority Queue is empty!!\n");
		return;
	}
	printf("\nThe element with maximum priority is:\n");
	printf("Priority: %d\nName: %s\n\n",priorityQueueRoot->priority,priorityQueueRoot->name);
	return;
}

void printPriorityQueue(HEAP priorityQueueRoot)
{
	if(count==0)
	{
		printf("\nPriority Queue already empty!!\n");
		return;
	}
	printf("\nInorder Traversal\n");
	inOrderTraversal(priorityQueueRoot);
	return;
}

void getInputFromFile(char *fileName, int userInteraction, HEAP priorityQueueRoot)
{
	FILE *filePointer;
	char buffer[51];
        if ( (filePointer =fopen( fileName, "r" ))== NULL )
        {
        	printf( "Could not open file\n" );
		exit(-1);	
        }

	int option,priority,cont;
	char name[21];
    	while  ((fscanf(filePointer,"%d",&option))>0) 
    	{
		if(option==1)
		{
			fscanf(filePointer,"%s %d", name,&priority);
			insertElement(name,priority,priorityQueueRoot);		
		}
		else if (option==2)
			deleteMax(priorityQueueRoot);
					
		else if(option==3)
			getMax(priorityQueueRoot);

		else if(option==4)
			printPriorityQueue(priorityQueueRoot);

		fgets(buffer,50, filePointer);
		if(userInteraction==1)
		{
			printf("\nEnter any number to continue: ");
			scanf("%d",&cont);
		}
        }
        
	fclose( filePointer );

	return;
}

int main(int argc, char *argv[])
{
	int userInteraction;
	HEAP priorityQueueRoot;
	priorityQueueRoot=getHeapNode();
	priorityQueueRoot->name[0]='\0';
	priorityQueueRoot->rightChild=NULL;
	priorityQueueRoot->leftChild=NULL;
	priorityQueueRoot->rightChild=NULL;
	if ( argc != 2 ) //argc should be 2 for correct execution
	{
       		printf( "usage: %s filename\n\n", argv[0] );//argc[0] will be the executable name
		exit(-1);
	}
	system("clear");
	printf("Do you want user interaction:\n1.Yes\n2.No\n");
	printf("\nEnter your choice : ");
	scanf("%d",&userInteraction);

	getInputFromFile(argv[1],userInteraction,priorityQueueRoot);

	return 0;        
}
