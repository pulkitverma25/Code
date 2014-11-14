/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _FORD_FULKERSON
#define _FORD_FULKERSON

void performDFS(int** graph,int* visitedVertex,int *predecessor,int vertexCount,int start);
int isPath(int** graph,int* visitedVertex,int *predecessor,int vertexCount,int src,int dest);
int getMinimumCapacity(int** graph,int* predecessor,int src,int dest);
void fordFulkerson(int** graph,int** residualGraph,int** flowGraph,int* visitedVertex,int* predecessor,int vertexCount,int src,int sink);
void initializeFordFulkerson(int** graph,int vertexCount,int src,int sink);

#endif
