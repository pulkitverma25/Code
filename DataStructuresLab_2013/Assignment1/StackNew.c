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
