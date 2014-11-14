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

#define DEFAULT_PRIORITY_VALUE 100000

int nodeCount=0;

struct graphedge
{
	int startVertex;
	int endVertex;
	int weight;
};
typedef struct graphedge* EDGE;

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

	for(k=0;k<count;k++) 
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

				tempNode->priority=newPriority+deletedKeyWeight;
				prevNode[(tempNode->keyId)-1]=toBeDeletedKey;
				heapifyUp(tempNode,locationVector);
			}
			else
			{
				altPriority=newPriority+deletedKeyWeight;
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

	 //Decrease the node count
	dijkastra(vertex,priorityQueueRoot,locationVector,prevNode,1,weightArray);


	return;

}

int* func(int count, int startingNode,char* fileName)
{
	LINKED_LIST *vertex; //To store the adjacency list
	vertex=NULL;
	int i;
//Count the number of nodes in adjacency list
	vertex=(LINKED_LIST*)readAdjacencyList(fileName,vertex,count); //Read the adjacency list from file
	if(startingNode==1)	
	printAdjacencyList(vertex,count); //Prints the adjacency list

	int *locationVector=(int*)malloc(sizeof(int)*count);
	int *prevNode=(int*)malloc(sizeof(int)*count);
	int *weightArray=(int*)malloc(sizeof(int)*count);
	for(i=0;i<count;i++)
	{
		locationVector[i]=0;
		prevNode[i]=-1;
		weightArray[i]=-1;
	}

	HEAP priorityQueueRoot;
	priorityQueueRoot=createPriorityQueue(vertex,count,locationVector);

	//inOrderTraversal(priorityQueueRoot);



		prevNode[startingNode-1]=startingNode;
		changeDijkastraPriority(startingNode,0,locationVector,priorityQueueRoot,prevNode,0,startingNode);

	dijkastra(vertex, priorityQueueRoot,locationVector,prevNode,startingNode,weightArray);
	/*
	printf("\n\nShortest Paths from Node %d to:\n",startingNode);
	for(i=0;i<count;i++)
	{
		temp=0;
		prev=prevNode[i];
		//printf("Inside temp, prev=%d",prev);
		printf("\nNode %d| Weight= %d | Path= %d",i+1,weightArray[i],i+1);
		while(prev!=startingNode)
		{
			//printf("Inside temp");
			temp=prevNode[prev-1];
			printf("->%d",prev);
			prev=temp;
			//temp=0;
		}
		printf("->%d",startingNode);
	}
	printf("\n\n");
	*/
	return weightArray;
}

void insertsort (EDGE* x, int n)
{
	int i,k,y;
	EDGE temp;

	for (k=1; k<n; k++)
	{
		y=x[k]->weight;
		temp->startVertex=x[k]->startVertex;
		temp->endVertex=x[k]->endVertex;
		temp->weight=x[k]->weight;
		for (i=k-1; i>=0 && y<x[i]->weight; i--)
		{
			x[i+1]->startVertex=x[i]->startVertex;
			x[i+1]->endVertex=x[i]->endVertex;
			x[i+1]->weight=x[i]->weight;
			
		}
		x[i+1]->startVertex=temp->startVertex;
		x[i+1]->endVertex=temp->endVertex;
		x[i+1]->weight=temp->weight;
	}

	printf("\n\n\n");

}

int isPath(int** adjacencyMatrix,int count,int startNode,int endNode)
{
	int i,path;
	for(i=0;i<count;i++)
		if(adjacencyMatrix[startNode][i]==1)
			{
				path=isPath(adjacencyMatrix,count,i,endNode);
				if(path==1 && i==endNode)
					return 1;
			}
		
	return 0;
}

int main(int argc, char *argv[])
{
	if ( argc != 2 ) //argc should be 2 for correct execution
	{
       		printf( "usage: %s filename\n\n", argv[0] );//argc[0] will be the executable name
		exit(-1);
	}
	system("clear");

	char fileName[30];
	int i,j;
	strcpy(fileName,argv[1]);

	int count=getNodeCount(fileName); 

	//******Minimum Weight for all (u,v)*****
	int** minWeightArray=(int**)malloc(sizeof(int*)*count);
	for(i=0;i<count;i++)
		minWeightArray[i]=(int*)malloc(sizeof(int)*count);

	for(i=0;i<count;i++)
		minWeightArray[i]=func(count, i+1,fileName);
	printf("\n");

	//****************************************

	LINKED_LIST *vertex2; //To store the adjacency list
	vertex2=NULL;

	vertex2=(LINKED_LIST*)readAdjacencyList(fileName,vertex2,count);

	int maxEdgeCount=count*count;
	EDGE* edgeArray=(EDGE*)malloc(sizeof(EDGE*)*maxEdgeCount*maxEdgeCount);
	int k=0,z,skip=0;
	//printAdjacencyList(vertex2,count);
	for(i=0;i<count;i++)
	{
		LINKED_LIST tempNode=getNode();
		tempNode=vertex2[i]->next;	
		while(tempNode != NULL)
		{
			skip=0;
			
			for(z=0;z<=k-1;z++)
			{
				if(edgeArray[z]->startVertex==tempNode->key && edgeArray[z]->endVertex==i+1)
				{
					skip=1;
					break;
				}
			}
		
			if(skip==0)
			{
			edgeArray[k]=(EDGE)malloc(sizeof(struct graphedge));
			edgeArray[k]->startVertex=i+1;
			edgeArray[k]->endVertex=tempNode->key;
			edgeArray[k]->weight=tempNode->weight;
			k++;
			//printf("->(%d,%d)",tempNode->key,tempNode->weight);
			}

			
			tempNode=tempNode->next;
		}
		
	}


	insertsort(edgeArray,k);	

	printf("Sorted Array of edges:\n");
	for(i=0;i<k;i++)
	{
		
		printf("start=%d\tend=%d\tweight=%d\n",edgeArray[i]->startVertex,edgeArray[i]->endVertex,edgeArray[i]->weight);

	}


	//STEP3
	int** adjacencyMatrixH=(int**)malloc(sizeof(int*)*count);
	for(i=0;i<count;i++)
		adjacencyMatrixH[i]=(int*)malloc(sizeof(int)*count);
	
	for(i=0;i<count;i++)
		for(j=0;j<count;j++)
			adjacencyMatrixH[i][j]=0;

	int node1,node2;
	for(i=0;i<k;i++)
	{
		node1=edgeArray[i]->startVertex;
		node2=edgeArray[i]->endVertex;

		if(isPath(adjacencyMatrixH,count,node1,node2)==0)
			adjacencyMatrixH[node1-1][node2-1]=1;

		//if(adjacencyMatrixH[node1-1][node2-1]==0)
			//adjacencyMatrixH[node1-1][node2-1]=1;
		else
			if(k*minWeightArray[node1-1][node2-1]<minWeightArray[node1-1][node2-1])
				adjacencyMatrixH[node1-1][node2-1]=1;
	}

	printf("\n\nAdjacency Matrix of Graph H\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
			printf("%d\t",adjacencyMatrixH[i][j]);
	printf("\n");
	}
	return 0;
}
