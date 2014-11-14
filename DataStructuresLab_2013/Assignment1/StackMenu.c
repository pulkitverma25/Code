/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _STACKNEW
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#endif

int main()
{
	int poppedNumber,choice,exitButton=-1,tempNumber1;
	STACK myStackHead;
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;


		do
	{
		system("clear");		
		printf("\nMENU\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print Stack\n");
		printf("4. Exit\n");

		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element to Push: \n");
				scanf("%d",&tempNumber1);
				push(myStackHead,tempNumber1);	
				printStack(myStackHead);
				break;

			case 2:
				tempNumber1=pop(myStackHead);
				if(tempNumber1!=-1)
					printf("\nPopped:%d\n",tempNumber1);	
				printStack(myStackHead);
				break;

			case 3:
				printStack(myStackHead);	
				break;			

			case 4:
				exit(0);

		};		
		printf("\nEnter 0 to proceed: ");
		scanf("%d",&exitButton);																	
	}while(choice!=4 || exitButton!=0);

	return 0;
}
