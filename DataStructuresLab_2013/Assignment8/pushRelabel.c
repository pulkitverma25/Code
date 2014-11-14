/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "pushRelabel.h"

#define TRUE 1
#define FALSE 0
#define INFINITY 99999



void push(int** graph,int** capacity,int** flowGraph, int* vertexFlow,int src, int dest)
{
	int pushValue=(vertexFlow[src]<capacity[src][dest])?vertexFlow[src]:capacity[src][dest];
	flowGraph[src][dest]+=pushValue;
	flowGraph[dest][src]=-1*flowGraph[src][dest];
	vertexFlow[src]-=pushValue;
	vertexFlow[dest]+=pushValue;
	capacity[src][dest]=graph[src][dest]-flowGraph[src][dest];
	capacity[dest][src]=graph[dest][src]-flowGraph[dest][src];
	
	return;
}

void relabel(int** graph,int** capacity, int** flowGraph,int* vertexHeight,int vertexCount,int src)
{
	int i,minHeight = INFINITY;
	for (i = 0; i < vertexCount; i++)
		if(capacity[src][i]!=0)
		{
			if (capacity[src][i] - flowGraph[src][i] > 0)
			{
				minHeight = (minHeight<vertexHeight[i])?minHeight:vertexHeight[i];
				vertexHeight[src]=minHeight+1;
			}
		}

	return;
}

void initializePreFlow(int** graph, int** capacity, int** flowGraph,int* vertexFlow, int* vertexHeight,int src, int vertexCount)
{
	int i,j;
	for(i=0;i<vertexCount;i++)
	{
		vertexHeight[i]=0;
		vertexFlow[i]=0;
		for(j=0;j<vertexCount;j++)
		{
			flowGraph[i][j]=0;
			capacity[i][j]=graph[i][j];
		}
	}
	vertexHeight[src]=vertexCount;

	for(i=0;i<vertexCount;i++)
		if(graph[src][i]!=0)
		{
			flowGraph[src][i]=capacity[src][i];
			flowGraph[i][src]=-1*flowGraph[src][i];
			vertexFlow[i]=capacity[src][i];
			vertexFlow[src]-=capacity[src][i];
			capacity[src][i]=graph[src][i]-flowGraph[src][i];
			capacity[i][src]=graph[i][src]-flowGraph[i][src];
		}

	return;
}

void genericPushRelabel(int** graph, int** capacity, int** flowGraph,int* vertexFlow, int* vertexHeight,int src, int sink, int vertexCount)
{
	initializePreFlow(graph,capacity,flowGraph,vertexFlow,vertexHeight,src,vertexCount);

	QUEUE* tempQueue=(QUEUE*)malloc(sizeof(QUEUE));
	initializeQueue(tempQueue);
	int i;
	int* traversed=(int*)malloc(sizeof(int)*vertexCount);
	for(i=0;i<vertexCount;i++)
		traversed[i]=0;

	int tempV,tempH;
	for (i=0;i<vertexCount;i++)
		if(i!=sink && graph[src][i]!=0)
		{
			enqueue(tempQueue,i);
			traversed[i]=1;
		}	
	
	while(!isQueueEmpty(tempQueue))
	{
		tempV=tempQueue->q[tempQueue->head];
		tempH=-1;

		for(i=0;i<vertexCount && vertexFlow[tempV]>0;i++)
		{
			if (capacity[tempV][i] > 0)
			{
				if(vertexHeight[tempV]>vertexHeight[i])
				{
					push(graph,capacity,flowGraph,vertexFlow,tempV,i);
					if(traversed[i]==0 && i!=src && i!=sink)
					{
						traversed[i]=1;
						enqueue(tempQueue,i);
					}
				}
				else if(tempH==-1)
					tempH=vertexHeight[i];
				else
					tempH=(tempH<vertexHeight[i])?tempH:vertexHeight[i];
			}
		}

		if(vertexFlow[tempV]!=0)
			vertexHeight[tempV]=1+tempH;
				
		else
		{
			traversed[tempV]=0;
			dequeue(tempQueue);
		}
	}

	free(tempQueue);
	free(traversed);
	return;
}

void initializePushRelabelAlgorithm(int** graph,int vertexCount,int src,int sink)
{
	int i,j,maxCapacity=0;

	int* vertexFlow=(int*)malloc(sizeof(int)*vertexCount);
	int* vertexHeight=(int*)malloc(sizeof(int)*vertexCount);

	int** flowGraph=(int**)malloc(sizeof(int*)*vertexCount);
	for(i=0;i<vertexCount;i++)
		flowGraph[i]=(int*)malloc(sizeof(int)*vertexCount);

	int** capacity=(int**)malloc(sizeof(int*)*vertexCount);
	for(i=0;i<vertexCount;i++)
		capacity[i]=(int*)malloc(sizeof(int)*vertexCount);



	genericPushRelabel(graph,capacity,flowGraph,vertexFlow,vertexHeight,src,sink,vertexCount);

	printf("\nFlow Graph:\n");
	for(i=0;i<vertexCount;i++)
	{
		for(j=0;j<vertexCount;j++)
		{
			if(i==0 && flowGraph[i][j]>0)
				maxCapacity+=flowGraph[i][j];
			printf("%3d ",flowGraph[i][j]);
		}
		printf("\n");
	}
	printf("\nMaximum Flow Capacity of the Network= %d\n\n",maxCapacity);


	for(i=vertexCount-1;i>=0;i--)
	{
		free(flowGraph[i]);
		free(capacity[i]);
	}
	free(flowGraph);
	free(capacity);
	free(vertexFlow);
	free(vertexHeight);
	
	return;
}

