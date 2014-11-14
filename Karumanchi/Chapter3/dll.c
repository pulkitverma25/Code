/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>
#include <stdlib.h>

struct dllNode
{
	int data;
	struct dllNode *prev;
	struct dllNode *next;
};

void printDll(struct dllNode *head)
{
	struct dllNode *iterator;
	if(head==NULL)
	{
		printf("Linked List Empty!!\n");
		return;
	}
	iterator=head;

	while(iterator!=NULL)
	{
		printf("%d, ",iterator->data);
		iterator=iterator->next;
	}
	printf("\b\b \n");
	return;
}

int countDllNodes (struct dllNode *head)
{
	struct dllNode *iterator;
	int count;

	iterator=head;
	count=0;

	while(iterator!=NULL)
	{
		count++;
		iterator=iterator->next;
	}

	return count;
}

void insertIntoDll (struct dllNode **head,int data, int position)
{
	int k=1;
	struct dllNode *newNode,*p,*q;
	newNode=(struct dllNode *)malloc(sizeof(struct dllNode));
	if (newNode ==NULL)
	{
		printf("Memory Error!!\n");
		return;
	}
	newNode->data=data;
	newNode->next=newNode->prev=NULL;

	p=*head;
	
	if(position == 1)
	{
		newNode->next=p;
		if(*head != NULL)
			(*head)->prev=newNode;
		*head=newNode;
	}
	else
	{
		while(p !=NULL && k<position)
		{
			k++;
			q=p;
			p=p->next;
		}

		if(p==NULL)
		{
			newNode->prev=q;
			q->next=newNode;
		}
		else
		{
			newNode->prev=q;
			q->next=newNode;
			newNode->next=p;
			p->prev=newNode;
		}
	}
	return;
}

void deleteFromDll (struct dllNode **head, int position)
{
	int k=1;
	struct dllNode *p,*q;
	if(*head==NULL)
	{
		printf("Empty Linked List!!\n");
		return;
	}	
	p=*head;

	if(position==1)
	{
		*head=(*head)->next;
		if (*head != NULL)
			(*head)->prev=NULL;
		free(p);
	}
	else
	{
		while(p !=NULL && k<position)
		{
			k++;
			q=p;
			p=p->next;
		}

		if(p==NULL)
			printf("Position not found\n");
		else
		{
			q->next=p->next;
			if(p->next != NULL)
				p->next->prev=q;
			free(p);
		}
	}

	return;
}

void deleteDll (struct dllNode **head)
{
	struct dllNode *iterator,*tempNode;
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

	struct dllNode *head;
	int data,len;
	head=NULL;
	data=1;

	deleteFromDll(&head,len);
	printDll(head);	
	insertIntoDll(&head,data,1);
	insertIntoDll(&head,data+1,2);
	insertIntoDll(&head,data+2,3);
	insertIntoDll(&head,data+3,2);
	printDll(head);
	deleteFromDll(&head,1);
	printDll(head);
	len=countDllNodes(head);
	deleteFromDll(&head,len);
	printDll(head);	
	deleteFromDll(&head,3);
	printDll(head);	
	
	deleteDll(&head);

	return 0;
}

