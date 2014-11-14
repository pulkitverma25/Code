/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pushRelabel.h"

int main()
{
	system("clear");

	int vertexCount,i,j,edgeCount=0,src,dest,sink,capacity;
	char temp[20];
	
	scanf("%s %d",temp,&vertexCount);

	int** graph=(int**)malloc(sizeof(int*)*vertexCount);
	for(i=0;i<vertexCount;i++)
		graph[i]=(int*)malloc(sizeof(int)*vertexCount);

	for(i=0;i<vertexCount;i++)
		for(j=0;j<vertexCount;j++)
			graph[i][j]=0;

	for(i=0;i<3;i++)
		scanf("%s",temp);

	while(1)
	{
		scanf("%s",temp);
		if(!strcmp(temp,"end"))
			break;
		src=atoi(temp);
		scanf("%d %d",&dest,&capacity);
		edgeCount++;
		graph[src][dest]=capacity;
	}

	printf("\nGraph:\n");
	for(i=0;i<vertexCount;i++)
	{
		for(j=0;j<vertexCount;j++)
			printf("%2d ",graph[i][j]);
		printf("\n");
	}
	
	scanf("%s %d",temp,&src);
	scanf("%s %d",temp,&sink);

	printf("\nSource= %d",src);
	printf("\nSink= %d\n",sink);
		
	initializePushRelabelAlgorithm(graph,vertexCount,src,sink);

	for(i=vertexCount-1;i>=0;i--)
		free(graph[i]);
	free(graph);	

	return 0;
}
