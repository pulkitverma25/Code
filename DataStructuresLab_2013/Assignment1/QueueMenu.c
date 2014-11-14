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
	int dequeuedNumber,choice,exitButton=-1,tempNumber1;
	QUEUE myQueueHead;
	myQueueHead=(QUEUE)malloc(sizeof(struct queue));
	myQueueHead->front=getNode();
	myQueueHead->front->next=NULL;
	myQueueHead->rear=NULL;



		do
	{
		system("clear");		
		printf("\nMENU\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");

		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to Enqueue: \n");
				scanf("%d",&tempNumber1);
				enqueue(myQueueHead,tempNumber1);	
				printQueue(myQueueHead);
				break;

			case 2:
				tempNumber1=dequeue(myQueueHead);
				if(tempNumber1!=-1)
					printf("\nDequeued:%d\n",tempNumber1);	
				printQueue(myQueueHead);
				break;

			case 3:
				printQueue(myQueueHead);	
				break;			

			case 4:
				exit(0);

		};		
		printf("\nEnter 0 to proceed: ");
		scanf("%d",&exitButton);																	
	}while(choice!=4 || exitButton!=0);

	return 0;
}
