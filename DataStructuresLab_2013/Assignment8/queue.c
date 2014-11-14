/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0
#define QUEUESIZE 100

void initializeQueue(QUEUE *q)
{
	q->head = 0;
	q->tail = QUEUESIZE-1;
	q->count = 0;
}

void enqueue(QUEUE *q, int num)
{
	if (q->count >= QUEUESIZE)
		printf("ERROR: Queue Overflow\nCannot enqueue %d\n",num);
	else {
		q->tail=(q->tail+1)%QUEUESIZE;
		q->q[q->tail]=num;    
		q->count=q->count+1;
	}
	return;
}

int dequeue(QUEUE *q)
{
	int temp;
	if (q->count <= 0) printf("ERROR: Empty QUEUE\nCannot dequeue.\n");
	else {
		temp=q->q[q->head];
		q->head=(q->head+1)%QUEUESIZE;
		q->count=q->count-1;
	}
	return(temp);
}

int isQueueEmpty(QUEUE *q)
{
	if(q->count<=0) 
		return (TRUE);
	else 
		return (FALSE);
}

void printQueue(QUEUE *q)
{
	int i;
	printf("QUEUE: ");
	i=q->head; 
	while (i != q->tail) {
		printf("%d ",q->q[i]);
		i = (i+1) % QUEUESIZE;
	}

	printf("%d ",q->q[i]);
	printf("\n");

	return;
}
