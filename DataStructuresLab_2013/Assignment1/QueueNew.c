/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _QUEUENEW
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#endif

int main()
{
	int dequeuedNumber;
	QUEUE myQueueHead;
	myQueueHead=(QUEUE)malloc(sizeof(struct queue));
	myQueueHead->front=getNode();
	myQueueHead->front->next=NULL;
	myQueueHead->rear=NULL;

	enqueue(myQueueHead,1);	
	dequeuedNumber=dequeue(myQueueHead);
	if(dequeuedNumber!=-1)
		printf("\nDequeued:%d\n",dequeuedNumber);
	dequeuedNumber=dequeue(myQueueHead);
	if(dequeuedNumber!=-1)
		printf("\nDequeued:%d\n",dequeuedNumber);
	enqueue(myQueueHead,2);	
	enqueue(myQueueHead,3);
	dequeuedNumber=dequeue(myQueueHead);
	if(dequeuedNumber!=-1)
		printf("\nDequeued:%d\n",dequeuedNumber);
	enqueue(myQueueHead,4);
	dequeuedNumber=dequeue(myQueueHead);
	if(dequeuedNumber!=-1)
		printf("\nDequeued:%d\n",dequeuedNumber);
	enqueue(myQueueHead,5);	
	enqueue(myQueueHead,6);	
	enqueue(myQueueHead,7);
	dequeuedNumber=dequeue(myQueueHead);
	if(dequeuedNumber!=-1)
		printf("\nDequeued:%d\n",dequeuedNumber);	
	enqueue(myQueueHead,8);	

	printQueue(myQueueHead);	

	return 0;
}
