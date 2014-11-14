/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

//Assignment 3

#ifndef _LINKEDLIST
#define _LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include "readAdjacency.h"
#include "Queue.h"
#endif

#define INPUT_FILE "adjacency.txt"

void performDFS(LINKED_LIST *vertex,int start,int visitedVertex[])
//Actually performs the Depth First Search recursively
{
	 LINKED_LIST tempNode;
	 visitedVertex[start]=1; //Marks the starting vertex as visited
	 printf("%d\t",start+1); //Prints the visited vertex
	 tempNode=vertex[start]->next; //Moves to next node in adjacency list
	 while(tempNode!=NULL)
	 {
		 if(visitedVertex[((tempNode->key)-1)]==-1) //if node is not visited
	 		performDFS(vertex,(tempNode->key)-1,visitedVertex); //visit the node
		 tempNode=tempNode->next; //move to next element in linked list
	 }
	return;
}

void DFS(LINKED_LIST *vertex,int count,int startNode)
//Initialises the various variables related to Depth First Search
{
	int visitedVertex[count],k,visitedVertexCount=0; 
	for(k=0;k<count;k++) //sets all the vertexes as not visited
		visitedVertex[k]=-1; //-1 stands for not visited

	printf("\nDFS:\n");
	performDFS(vertex,startNode-1,visitedVertex); //calls the actual function to perform DFS
	
	do{ //This loop checks if any disconnected component is left
		for(k=0;k<count;k++)
		{
			if(visitedVertex[k]!=-1)
				visitedVertexCount++;
			else
			{
				printf("\nDisconnected Component:\n");
				performDFS(vertex,k,visitedVertex);
				break;			
			}
		}
			if(k==count)
				break;
	}while(visitedVertexCount!=count);

	return;
}

void performBFS(LINKED_LIST *vertex,int start,int visitedVertex[])
//Actually performs the Breadth First Search recursively
{
	LINKED_LIST tempNode;
	QUEUE myQueueHead; //Define queue for BFS
	myQueueHead=(QUEUE)malloc(sizeof(struct queue));
	myQueueHead->front=getNode();
	myQueueHead->front->next=NULL;
	myQueueHead->rear=NULL;
	int dequeuedNumber; //To store the dequeued number

	visitedVertex[start]=1; //Marks the starting vertex as visited
	printf("%d",start+1); //Prints the visited vertex
	enqueue(myQueueHead,start); //Put the vertex in queue
	while(!isQueueEmpty(myQueueHead)) //Till queue is not empty
	{
		dequeuedNumber=dequeue(myQueueHead); //Dequeue the visited vertex
		tempNode=vertex[dequeuedNumber]->next;
		while(tempNode!=NULL) //Runs till all the adjacent vertexes are enqueued
		{
			if(visitedVertex[((tempNode->key)-1)]==-1) //Checks if vertex is already visited or not
			{
	  			visitedVertex[((tempNode->key)-1)]=1; //Marks the node as visited
	  			printf("\t %d",tempNode->key); //Prints the visited vertex
				enqueue(myQueueHead,(tempNode->key)-1); //Enqueue the next visiting vertex
			}
			tempNode=tempNode->next;
		}
	 }
	free(myQueueHead); //Free the memory allocated to queue
	myQueueHead=NULL; //Marks the memory referenced by queue to NULL, to avoid invalid access after program termination

	return;
}

void BFS(LINKED_LIST *vertex,int count,int startNode)
//Initialises the various variables related to Depth First Search
{
	int visitedVertex[count],k,visitedVertexCount=0;

	for(k=0;k<count;k++) //sets all the vertexes as not visited
		visitedVertex[k]=-1; //-1 stands for not visited
	printf("\nBFS:\n");
	performBFS(vertex,startNode-1,visitedVertex); //calls the actual function to perform BFS

	do{ //This loop checks if any disconnected component is left
		for(k=0;k<count;k++)
		{
			if(visitedVertex[k]!=-1)
				visitedVertexCount++;
			else
			{
				printf("\nDisconnected Component:\n");
				performBFS(vertex,k,visitedVertex);
				break;			
			}

		}
			if(k==count)
				break;
	}while(visitedVertexCount!=count);

	return;
}

int main()
{
	LINKED_LIST *vertex; //To store the adjacency list
	vertex=NULL;

	int count=getNodeCount(INPUT_FILE); //Count the number of nodes in adjacency list
	vertex=readAdjacencyList(INPUT_FILE,vertex,count); //Read the adjacency list from file
	printAdjacencyList(vertex,count); //Prints the adjacency list
	int startNode;
	printf("\nDFS: \tEnter the starting node: ");
	scanf("%d",&startNode);
	
	DFS(vertex,count,startNode);
	printf("\n");

	startNode=0;
	printf("\nBFS: \tEnter the starting node: ");
	scanf("%d",&startNode);

	BFS(vertex,count,startNode);
	printf("\n");

	return 0;
}

/*****Input*Pattern*****
1 2 3 4
2 1 3 5
3 1 2 4 7
4 1 3 6
5 2 7
6 4 7
7 3 5 6
8 9
9 8 10
10 9
11 12
12 11
************************/
