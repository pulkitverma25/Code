/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "readAdjacency.h"
#include "linkedList.h"
#include "minHeap.h"
#include "dijNprim.h"

int main(int argc, char *argv[])
{
	int choice,exitButton=-1;
	if ( argc != 2 ) //argc should be 2 for correct execution
	{
       		printf( "usage: %s filename\n\n", argv[0] );//argc[0] will be the executable name
		exit(-1);
	}
	system("clear");

	LINKED_LIST *vertex; //To store the adjacency list
	vertex=NULL;
	int i,startingNode,prev,temp;
	int count=getNodeCount(argv[1]); //Count the number of nodes in adjacency list
	vertex=(LINKED_LIST*)readAdjacencyList(argv[1],vertex,count); //Read the adjacency list from file
	 //Prints the adjacency list

	int *locationVector=(int*)malloc(sizeof(int)*count);//Allocate memory to various array
	int *prevNode=(int*)malloc(sizeof(int)*count);
	int *weightArray=(int*)malloc(sizeof(int)*count);
	int *outputArray=(int*)malloc(sizeof(int)*count);
	for(i=0;i<count;i++) //Initialise the arrays to respective values
	{
		locationVector[i]=0;
		prevNode[i]=-1;
		weightArray[i]=-1;
		outputArray[i]=-1;
	}

	do
	{
		HEAP priorityQueueRoot;
		priorityQueueRoot=createPriorityQueue(vertex,count,locationVector);
		system("clear");		
		printf("\nMENU\n");
		printf("1. Dijkastra Algorithm\n");
		printf("2. Prims Algorithm\n");
		printf("3. Exit\n");

		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printAdjacencyList(vertex,count);
				printf("\nEnter the starting node : ");
				scanf("%d",&startingNode);

				prevNode[startingNode-1]=startingNode;
				changeDijkastraPriority(startingNode,0,locationVector,priorityQueueRoot,prevNode,0,startingNode); //change priority of initial node

				dijkastra(vertex, priorityQueueRoot,locationVector,prevNode,startingNode,weightArray); //apply Dijkastra

				printf("\n\nShortest Paths from Node %d to:\n",startingNode); //Print the output
				for(i=0;i<count;i++)
				{
					temp=0;
					prev=prevNode[i];
					printf("\nNode %d| Weight= %d | Path= %d",i+1,weightArray[i],i+1);
					while(prev!=startingNode)
					{
						temp=prevNode[prev-1];
						printf("->%d",prev);
						prev=temp;
					}
					printf("->%d",startingNode);
				}
				printf("\n\n");
				break;
			
			case 2:
				printAdjacencyList(vertex,count);
				printf("\nEnter the starting node : ");
				scanf("%d",&startingNode);

				prevNode[startingNode-1]=startingNode;
				changePrimsPriority(startingNode,0,locationVector,priorityQueueRoot,prevNode,0,startingNode);//change priority of initial node

				prims(vertex, priorityQueueRoot,locationVector,prevNode,startingNode,weightArray,outputArray,0); //apply Prims

				printf("\n\nMinimum Spanning tree from node %d:\n",startingNode); //Print the output
				int sum=0;
				for(i=0;i<count;i++)
				{
					printf("%d->",outputArray[i]);
					sum+=weightArray[i];
				}
				printf("\n\nTotal Weight %d:\n",sum);
				break;

			case 3:
				system("clear");
				exit(0);

		};		
		printf("\nEnter 0 to proceed: ");
		scanf("%d",&exitButton);																	
	}while(choice!=3 || exitButton!=0);

	return 0;
}

/*******SampleInput*****
1 2,10 4,30 5,45
2 1,10 3,50 5,40 6,25
3 2,50 5,35
4 1,30 6,20
5 1,45 2,40 3,35 6,55
6 2,25 4,20 5,55
***********************/


