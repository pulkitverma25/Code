/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/

/*
Implementation of stack using array
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void push (int i);
int pop (void);

int *tos, *p1, stack[SIZE];

int main(){
	int value;

	tos=stack;
	p1=stack;

	do{
		printf("Enter value : ");
		scanf("%d", &value);

		if (0 != value)
			push(value);

		else
			printf("value on top is %d\n",pop());

	}while (1 != value);

	return 0;
}

void push(int i){
	if(&stack[SIZE]==&tos){
		printf("Overflow");
		return;
	}
	else{
		stack[&tos]=value;
		tos++;
		return;
	}
}

int pop(){
	if(tos==stack){
		printf("Underflow");
		return -1;
	}
	else{
		return (&tos);
		tos--;
	}
}
