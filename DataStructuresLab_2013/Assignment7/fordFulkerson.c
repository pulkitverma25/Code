/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define INFINITY 99999

void performDFS(int** graph,int* visitedVertex,int *predecessor,int vertexCount,int start)
//Actually performs the Depth First Search recursively
{
	int i;
	visitedVertex[start]=1; //Marks the starting vertex as visited

	for(i=0;i<vertexCount;i++)
	{
		if(graph[start][i]==0) //If there is no edge
			continue;
		if(visitedVertex[i]==-1)
		{
			predecessor[i]=start; //Updates the predecessor values
			performDFS(graph,visitedVertex,predecessor,vertexCount,i); //recursively call DFS
		}
	}
	return;
}

int isPath(int** graph,int* visitedVertex,int *predecessor,int vertexCount,int src,int dest)
//Checks if there is a path in graph from src to dest
{
	predecessor[src]=INFINITY; //default parent of source set to infinity
	performDFS(graph,visitedVertex,predecessor,vertexCount,src); //call DFS
	if(visitedVertex[dest]<=-1)
		return FALSE;
	else
		return TRUE;
}

int getMinimumCapacity(int** graph,int* predecessor,int src,int dest)
//returns the minimum capacity of the path, returns INFINITY if no path
{
	int curr=dest,minCapacity=INFINITY,temp;
	
	while(predecessor[curr]!=-1 && predecessor[curr]!=INFINITY)//traces the path through predecessor array
	{
		temp=predecessor[curr];
		if(minCapacity>graph[temp][curr])
			minCapacity=graph[temp][curr];
		curr=temp;
	}
	return minCapacity;
}

void fordFulkerson(int** graph,int** residualGraph,int** flowGraph,int* visitedVertex,int* predecessor,int vertexCount,int src,int sink)
//Implements the Ford Fulkerson Algorithm using DFS
{
	int curr,temp,minCapacity,i,j;

	//Initializes the flow graph
	for(i=0;i<vertexCount;i++)
		for(j=0;j<vertexCount;j++)
			if(residualGraph[i][j]!=0)
				flowGraph[i][j]=flowGraph[j][i]=0;
	
	//Updates the flow graph till a path is available
	while(isPath(residualGraph,visitedVertex,predecessor,vertexCount,src,sink))
	{
		curr=sink;
		minCapacity=getMinimumCapacity(residualGraph,predecessor,src,sink); //gets the minimum capacity
		while(predecessor[curr]!=-1 && predecessor[curr]!=INFINITY) //For each edge in (u,v) update flow graph and residual graph
		{
			temp=predecessor[curr];
			flowGraph[temp][curr]+=minCapacity;
			flowGraph[curr][temp]=(-1)*flowGraph[temp][curr];			
			residualGraph[temp][curr]-=minCapacity;
			residualGraph[curr][temp]+=minCapacity;
			curr=temp;
		}
		
		for(i=0;i<vertexCount;i++) //reset the arrays for DFS
		{
			visitedVertex[i]=-1;
			predecessor[i]=-1;
		}
	}
	return;
}

void initializeFordFulkerson(int** graph,int vertexCount,int src,int sink)
//Prepares the data structures for applying Ford Fulkerson Algorithm
{
	int i,j,maxCapacity=0;

	int* visitedVertex=(int*)malloc(sizeof(int)*vertexCount);
	int* predecessor=(int*)malloc(sizeof(int)*vertexCount);

	int** residualGraph=(int**)malloc(sizeof(int*)*vertexCount);
	for(i=0;i<vertexCount;i++)
		residualGraph[i]=(int*)malloc(sizeof(int)*vertexCount);

	int** flowGraph=(int**)malloc(sizeof(int*)*vertexCount);
	for(i=0;i<vertexCount;i++)
		flowGraph[i]=(int*)malloc(sizeof(int)*vertexCount);

	for(i=0;i<vertexCount;i++)
	{
		visitedVertex[i]=-1;
		predecessor[i]=-1;
		for(j=0;j<vertexCount;j++)
		{
			flowGraph[i][j]=0;
			residualGraph[i][j]=graph[i][j];
		}
	}

	fordFulkerson(graph,residualGraph,flowGraph,visitedVertex,predecessor,vertexCount,src,sink);

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
		free(residualGraph[i]);
	}
	free(flowGraph);
	free(residualGraph);
	free(visitedVertex);
	free(predecessor);
	
	return;
}

