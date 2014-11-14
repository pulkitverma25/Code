/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>
#include <stdlib.h>

struct linkedListNode
{
	int data;
	struct linkedListNode *next;
};

void insertIntoLinkedList (struct linkedListNode **head, int data, int position)
{
	int k=1;
	struct linkedListNode *newNode,*p,*q;
	
	newNode=(struct linkedListNode *) malloc (sizeof (struct linkedListNode));
	if (newNode == NULL)
	{
		printf("\nMemory Error!!\n");
		return;
	}
	newNode->data=data;
	p=*head;

	if (position==1)
	{
		newNode->next=p;
		*head=newNode;
	}
	else
	{
		while(p != NULL && k<position)
		{
			k++;
			q=p;
			p=p->next;
		}

		q->next=newNode;
		if (p == NULL)
			newNode->next=NULL;
		else
			newNode->next=p;		
	}
	return;
}

void deleteFromLinkedList (struct linkedListNode **head, int position)
{
	int k=1;
	struct linkedListNode *p,*q;
	
	if (*head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	p=*head;
	
	if(position==1)	
	{
		*head=p->next;
		free(p);
	}	
	else
	{
		while(p!=NULL && k< position)
		{
			k++;
			q=p;
			p=p->next;
		}
		if (p==NULL && k==position-1)
			q->next=NULL;
		else if (p==NULL && k!=position-1)
		{
			printf("Position not found!!\n");
			return;
		}
		else
			q->next=p->next;

		free(p);
	}
	return;	
}

void printLinkedList(struct linkedListNode *head)
{
	struct linkedListNode *iterator;
	if (head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	iterator=head;

	while(iterator !=NULL)
	{
		printf("%d, ",iterator->data);
		iterator = iterator->next;
	}
	printf("\b\b \n");

	return;
}

int getLinkedListLength(struct linkedListNode *head)
{
	int count;
	struct linkedListNode *iterator;
	iterator=head;
	count=0;

	while(iterator !=NULL)
	{
		count++;
		iterator = iterator->next;
	}
	
	return count;
}

void deleteLinkedList(struct linkedListNode **head)
{
	struct linkedListNode *iterator,*tempNode;
	iterator=*head;

	while(iterator != NULL)
	{
		tempNode=iterator;
		iterator=iterator->next;
		free(tempNode);
	}

	*head=NULL;
	return;
}

int main()
{
	struct linkedListNode *head;
	int data,len;
	head=NULL;
	data=1;

	deleteFromLinkedList(&head,len);
	printLinkedList(head);	
	insertIntoLinkedList(&head,data,1);
	insertIntoLinkedList(&head,data+1,2);
	insertIntoLinkedList(&head,data+2,3);
	insertIntoLinkedList(&head,data+3,2);
	printLinkedList(head);
	deleteFromLinkedList(&head,1);
	printLinkedList(head);
	len=getLinkedListLength(head);
	deleteFromLinkedList(&head,len);
	printLinkedList(head);	
	deleteFromLinkedList(&head,3);
	printLinkedList(head);	
	
	deleteLinkedList(&head);

	return 0;	
}
