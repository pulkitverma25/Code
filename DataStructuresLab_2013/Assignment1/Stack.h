/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _STACK
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#endif

struct stack
{
	LINKED_LIST top;
};

typedef struct stack *STACK;

int isStackEmpty(STACK stack)
{
	if (stack->top->next==NULL)
		return TRUE;
	else
		return FALSE;
}

void push(STACK stack, int number)
{
	LINKED_LIST newElement = getNode();
	if(newElement==NULL)
	{
		printf("ERROR: Memory Full");
	}
	else
	{
		newElement->key=number;
		newElement->next=stack->top->next;
		stack->top->next=newElement;
	}
	return;
}

int pop(STACK stack)
{
	LINKED_LIST deletedElement = getNode();
	int poppedNumber;
	if(deletedElement==NULL)
	{
		printf("ERROR: Memory Full");
		return -1;
	}
	else
	{
		if(isStackEmpty(stack))
		{
			printf("ERROR: Stack Underflow");
			return -1;	
		}
		else
		{
			deletedElement=stack->top->next;
			stack->top->next=stack->top->next->next;
			poppedNumber=deletedElement->key;

			free(deletedElement);
			deletedElement=NULL;		
		
			return poppedNumber;
		}
	}
}

void printStack(STACK stack)
{
	printf("\nStack:\n");
	printLinkedList(stack->top);
}


