/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "readAdjacency.h"
#include "linkedList.h"
#include "stack.h"
#include "minHeap.h"
#include "dijNprim.h"

#define DEFAULT_PRIORITY_VALUE 100000

int nodeCount=0;

void insertElement(int keyId, int priority, HEAP priorityQueueRoot,int* locationVector)
{
	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode->priority=priority;
	tempNode->keyId=keyId;
	tempNode->leftChild=NULL;
	tempNode->rightChild=NULL;
	tempNode->parent=NULL;
	nodeCount++;
	addElementToHeap(priorityQueueRoot,tempNode,nodeCount,locationVector);
	return;
}

HEAP createPriorityQueue(LINKED_LIST* vertex,int count,int* locationVector)
{
	if(count<=0)
		exit(-1);

	HEAP priorityQueueRoot;
	priorityQueueRoot=getHeapNode();
	priorityQueueRoot->keyId=-1;
	priorityQueueRoot->priority=DEFAULT_PRIORITY_VALUE;
	priorityQueueRoot->rightChild=NULL;
	priorityQueueRoot->leftChild=NULL;
	priorityQueueRoot->rightChild=NULL;


	int k;

	for(k=0;k<count;k++) //Initialize the priority queue
	{
		locationVector[k]=k+1;
		insertElement(k+1,DEFAULT_PRIORITY_VALUE,priorityQueueRoot,locationVector);
	}

	return priorityQueueRoot;
}

void changeDijkastraPriority(int position,int newPriority, int* locationVector,HEAP rootElement, int* prevNode, int deletedKeyWeight,int toBeDeletedKey)
{
	int poppedNumber,pushNumber; 
	STACK myStackHead; //Stack used to find where to move to trace the element
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;

	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode=rootElement;
	int altPriority;
	
	int temp=position;
	while(temp!=0) //Get binary form of count
	{
		pushNumber=temp%2; //Remainder is pused on stack
		temp/=2;
		push(myStackHead,pushNumber);

	}

	poppedNumber=pop(myStackHead); //last number represents the root element so popped out
	if(poppedNumber==-1)
		return;
	while(1)
	{
		poppedNumber=pop(myStackHead); //pop the number on stack
		if(poppedNumber==-1) //If location reached
		{


			if(tempNode->priority==DEFAULT_PRIORITY_VALUE)
			{

				tempNode->priority=newPriority+deletedKeyWeight; //Add the new weight
				prevNode[(tempNode->keyId)-1]=toBeDeletedKey; 
				heapifyUp(tempNode,locationVector); //maintain the heapify property
			}
			else
			{
				altPriority=newPriority+deletedKeyWeight; //Add the new weight
				if((tempNode->priority)>altPriority) //see if new weight is less
				{
					prevNode[(tempNode->keyId)-1]=toBeDeletedKey;
					tempNode->priority=altPriority;
				}
				heapifyDown(tempNode,locationVector); //maintain the heapify property
			}
			break;
		}			
		else if(poppedNumber==0) //If popped number is 0 then move left
		{
			tempNode=tempNode->leftChild;
			temp=poppedNumber;
		}
		else if(poppedNumber==1) //If popped number is 1 then move right
		{
			tempNode=tempNode->rightChild;
			temp=poppedNumber;
		}
	}
	return;

}


void dijkastra(LINKED_LIST *vertex, HEAP priorityQueueRoot,int *locationVector,int *prevNode,int startingNode,int* weightArray)
{	
	int tempKey,position;
	int tempWeightage;
	int toBeDeletedKey,deletedKeyWeight;

	inOrderTraversal(priorityQueueRoot);
	if(nodeCount==0) //If queue is empty then nothing can be deleted further
	{
		return;
	}
	else if(nodeCount==1) //If there is any element in heap tree
	{
		toBeDeletedKey=priorityQueueRoot->keyId;
		deletedKeyWeight=priorityQueueRoot->priority;
		weightArray[toBeDeletedKey-1]=deletedKeyWeight;
		nodeCount--; //Decrease the node count
		priorityQueueRoot->keyId=DEFAULT_PRIORITY_VALUE;
		priorityQueueRoot->rightChild=NULL;
		priorityQueueRoot->leftChild=NULL;
		priorityQueueRoot->rightChild=NULL;
		return;
	}
	else
	{
		toBeDeletedKey=priorityQueueRoot->keyId;
		deletedKeyWeight=priorityQueueRoot->priority;
		weightArray[toBeDeletedKey-1]=deletedKeyWeight;
		LINKED_LIST tempNode=vertex[toBeDeletedKey-1]->next;
		deleteElementFromHeap (priorityQueueRoot, nodeCount,locationVector); //delete the element
		nodeCount--;

		locationVector[toBeDeletedKey-1]=0;

		while(tempNode!=NULL)
		{
			tempKey=tempNode->key;
			tempWeightage=tempNode->weight;
						
			position=locationVector[tempKey-1];
			changeDijkastraPriority(position,tempWeightage,locationVector,priorityQueueRoot,prevNode,deletedKeyWeight,toBeDeletedKey);

			tempNode=tempNode->next;
		}
	}
	dijkastra(vertex,priorityQueueRoot,locationVector,prevNode,1,weightArray);

	return;
}

void changePrimsPriority(int position,int newPriority, int* locationVector,HEAP rootElement, int* prevNode, int deletedKeyWeight,int toBeDeletedKey)
{
	int poppedNumber,pushNumber; 
	STACK myStackHead; //Stack used to find where to move to trace the element
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;

	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode=rootElement;
	int altPriority;
	
	int temp=position;
	while(temp!=0) //Get binary form of count
	{
		pushNumber=temp%2; //Remainder is pused on stack
		temp/=2;
		push(myStackHead,pushNumber);

	}

	poppedNumber=pop(myStackHead); //last number represents the root element so popped out
	if(poppedNumber==-1)
		return;
	while(1)
	{
		poppedNumber=pop(myStackHead); //pop the number on stack
		if(poppedNumber==-1) //If location reached
		{
			if(tempNode->priority==DEFAULT_PRIORITY_VALUE)
			{
				tempNode->priority=newPriority;
				prevNode[(tempNode->keyId)-1]=toBeDeletedKey;
				heapifyUp(tempNode,locationVector);
			}
			else
			{
				altPriority=newPriority;
				if((tempNode->priority)>altPriority)
				{
					prevNode[(tempNode->keyId)-1]=toBeDeletedKey;
					tempNode->priority=altPriority;
				}
				heapifyDown(tempNode,locationVector);
			}
			break;
		}			
		else if(poppedNumber==0) //If popped number is 0 then move left
		{
			tempNode=tempNode->leftChild;
			temp=poppedNumber;
		}
		else if(poppedNumber==1) //If popped number is 1 then move right
		{
			tempNode=tempNode->rightChild;
			temp=poppedNumber;
		}
	}
	return;

}

void prims(LINKED_LIST *vertex, HEAP priorityQueueRoot,int *locationVector,int *prevNode,int startingNode,int* weightArray,int *outputArray, int i)
{	
	int tempKey,position;
	int tempWeightage;
	int toBeDeletedKey,deletedKeyWeight;

	inOrderTraversal(priorityQueueRoot);
	if(nodeCount==0) //If queue is empty then nothing can be deleted further
	{
		return;
	}
	else if(nodeCount==1) //If there is any element in heap tree
	{
		toBeDeletedKey=priorityQueueRoot->keyId;
		deletedKeyWeight=priorityQueueRoot->priority;
		outputArray[i]=toBeDeletedKey;
		weightArray[i]=deletedKeyWeight;
		i++;
		nodeCount--; //Decrease the node count
		priorityQueueRoot->keyId=DEFAULT_PRIORITY_VALUE;
		priorityQueueRoot->rightChild=NULL;
		priorityQueueRoot->leftChild=NULL;
		priorityQueueRoot->rightChild=NULL;
		return;
	}
	else
	{		
		toBeDeletedKey=priorityQueueRoot->keyId;
		deletedKeyWeight=priorityQueueRoot->priority;
		outputArray[i]=toBeDeletedKey;
		weightArray[i]=deletedKeyWeight;
		i++;
		LINKED_LIST tempNode=vertex[toBeDeletedKey-1]->next;
		deleteElementFromHeap (priorityQueueRoot, nodeCount,locationVector); //delete the element
		nodeCount--;

		locationVector[toBeDeletedKey-1]=0;

		while(tempNode!=NULL)
		{
			tempKey=tempNode->key;
			tempWeightage=tempNode->weight;
			
			position=locationVector[tempKey-1];
			changePrimsPriority(position,tempWeightage,locationVector,priorityQueueRoot,prevNode,deletedKeyWeight,toBeDeletedKey);

			tempNode=tempNode->next;
		}
	}

	prims(vertex,priorityQueueRoot,locationVector,prevNode,1,weightArray,outputArray,i);

	return;
}

