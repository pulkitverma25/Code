/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef STACK_H_
#define STACK_H_

#include"linkedList.h"

struct stack
{
	LINKED_LIST top;
};

typedef struct stack *STACK;

int isStackEmpty(STACK stack);
void push(STACK stack, int number);
int pop(STACK stack);
void printStack(STACK stack);

#endif
