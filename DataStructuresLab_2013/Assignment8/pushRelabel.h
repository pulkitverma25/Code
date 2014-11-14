/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef PUSH_RELABEL_H_
#define PUSH_RELABEL_H_

void push(int** graph,int** capacity,int** flowGraph, int* vertexFlow,int src, int dest);
void relabel(int** graph,int** capacity, int** flowGraph,int* vertexHeight,int vertexCount,int src);
void initializePreFlow(int** graph, int** capacity, int** flowGraph,int* vertexFlow, int* vertexHeight,int src, int vertexCount);
void genericPushRelabel(int** graph, int** capacity, int** flowGraph,int* vertexFlow, int* vertexHeight,int src, int sink, int vertexCount);
void initializePushRelabelAlgorithm(int** graph,int vertexCount,int src,int sink);

#endif
