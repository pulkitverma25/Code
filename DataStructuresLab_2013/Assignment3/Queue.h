/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

//Assignment 1

#ifndef _LINKEDLIST
#define _LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#endif

struct queue
{
	LINKED_LIST front,rear;
};

typedef struct queue *QUEUE;

int isQueueEmpty(QUEUE queue)
{
	if (queue->front->next==NULL)
		return TRUE;
	else
		return FALSE;
}

void enqueue(QUEUE queue, int number)
{
	LINKED_LIST newElement = getNode();
	if(newElement==NULL)
	{
		printf("ERROR: Memory Full");
	}
	else
	{
		newElement->key=number;
		newElement->next=NULL;
		if(queue->rear==NULL)
			queue->front->next=newElement;
		else
			queue->rear->next=newElement;

		queue->rear=newElement;
	}
	return;
}

int dequeue(QUEUE queue)
{
	LINKED_LIST deletedElement = getNode();
	int dequeuedNumber;
	if(deletedElement==NULL)
	{
		printf("ERROR: Memory Full");
		return -1;
	}
	else
	{
		if(isQueueEmpty(queue))
		{
			printf("\nERROR: Empty Queue\n");
			return -1;
		}
		else
		{
			deletedElement=queue->front->next;
			queue->front->next=queue->front->next->next;
			dequeuedNumber=deletedElement->key;

			if(queue->front->next==NULL)
				queue->rear=NULL;

			free(deletedElement);
			deletedElement=NULL;

			return dequeuedNumber;
		}
	}
}

void printQueue(QUEUE queue)
{
	printLinkedList(queue->front);
}
