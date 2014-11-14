/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUESIZE 100

typedef struct {
	int q[QUEUESIZE+1];
	int head; 
	int tail;
	int count;
} QUEUE;

void initializeQueue(QUEUE *q);
void enqueue(QUEUE *q, int num);
int dequeue(QUEUE *q);
int isQueueEmpty(QUEUE *q);
void printQueue(QUEUE *q);

#endif
