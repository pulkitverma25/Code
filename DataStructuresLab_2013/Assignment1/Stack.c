/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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
	int poppedNumber;
	if(isStackEmpty(stack))
	{
		printf("ERROR: Stack Underflow");
		return -1;	
	}
	else
	{
		poppedNumber=stack->top->next->key;
		stack->top->next=stack->top->next->next;
		return poppedNumber;
	}
}

void printStack(STACK stack)
{
	printLinkedList(stack->top);
}

int main()
{
	int poppedNumber;
	STACK myStackHead;
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;
	push(myStackHead,1);	
	poppedNumber=pop(myStackHead);
	if(poppedNumber!=-1)
		printf("\nPopped:%d\n",poppedNumber);
	poppedNumber=pop(myStackHead);
	if(poppedNumber!=-1)
		printf("\nPopped:%d\n",poppedNumber);
	push(myStackHead,2);	
	push(myStackHead,3);
	poppedNumber=pop(myStackHead);
	if(poppedNumber!=-1)
		printf("\nPopped:%d\n",poppedNumber);
	push(myStackHead,4);
	poppedNumber=pop(myStackHead);
	if(poppedNumber!=-1)
		printf("\nPopped:%d\n",poppedNumber);
	push(myStackHead,5);	
	push(myStackHead,6);	
	push(myStackHead,7);
	poppedNumber=pop(myStackHead);
	if(poppedNumber!=-1)
		printf("\nPopped:%d\n",poppedNumber);	
	push(myStackHead,8);	

	printStack(myStackHead);	

	return 0;
}
