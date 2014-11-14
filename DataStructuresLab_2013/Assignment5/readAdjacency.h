/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef READADJACENCY_H_
#define READADJACENCY_H_

#include "linkedList.h"

int getNodeCount(char *inputFile);
LINKED_LIST* readAdjacencyList(char *inputFile,LINKED_LIST *vertex,int count);
void printList(LINKED_LIST head);
void printAdjacencyList(LINKED_LIST *vertex, int count);

#endif



