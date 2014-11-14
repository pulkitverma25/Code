/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node* next;
};
typedef struct node* LINKED_LIST;

LINKED_LIST getNode()
{
	LINKED_LIST newNode;
	newNode=(LINKED_LIST)malloc(sizeof(struct node));
	
	return newNode;
}

LINKED_LIST listSearch(LINKED_LIST head, int element)
{
	LINKED_LIST tempNode=getNode();
	
	tempNode=head->next;
	while(tempNode != NULL && tempNode->key!=element)
	{
		tempNode=tempNode->next;
	}
	return tempNode;
}

void insertAtHead(LINKED_LIST head, LINKED_LIST newNode)
{
	newNode->next=head->next;
	head->next=newNode;
	
	return;
}

int deleteNode(LINKED_LIST head, LINKED_LIST nodeToDelete)
{
	if(head==NULL || head->next==NULL)
	{
		printf("\nERROR: Empty List\n");
		return -1;
	}
	LINKED_LIST tempNode=getNode();
	int deletedKey;
	tempNode=head;

	while(tempNode != NULL && tempNode->next!=nodeToDelete)
	{
		tempNode=tempNode->next;
	}
	if(tempNode==NULL)
	{
		printf("\nERROR: Node not found\n");
		return -1;
	}
	deletedKey=tempNode->next->key;
	if(nodeToDelete->next!=NULL)
		tempNode->next=nodeToDelete->next;
	else
		tempNode->next=NULL;

	free(nodeToDelete);
	nodeToDelete=NULL;

	return deletedKey;
}

LINKED_LIST findLastNode(LINKED_LIST head)
{
	LINKED_LIST tempNode=getNode();
	tempNode=head;
	while(tempNode != NULL && tempNode->next!=NULL)
	{
		tempNode=tempNode->next;
	}
	return tempNode;
}

void printLinkedList(LINKED_LIST head)
{
	if(head->next==NULL || head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else{
	LINKED_LIST tempNode=getNode();
	tempNode=head->next;	
	printf("\nLinked List:\n");
	while(tempNode != NULL)
	{
		printf("%d\t",tempNode->key);
		tempNode=tempNode->next;
	}
	printf("\n\n");
	}
	return;
}

int main()
{
	int i;
	LINKED_LIST myListHead=getNode();
	myListHead->next=NULL;

	for(i=0;i<10;i++)
	{
		LINKED_LIST tempNode=getNode();
		tempNode->key=i;
		insertAtHead(myListHead,tempNode);
	}


	printLinkedList(myListHead);


	LINKED_LIST searchElement;
	searchElement=getNode();

	searchElement=listSearch(myListHead,4);	

	printf("\n\nSearchedElement:%d\n",searchElement->key);

	LINKED_LIST lastNode;
	searchElement=getNode();

	searchElement=findLastNode(myListHead);	

	printf("\n\nLastNode:%d\n",searchElement->key);


	LINKED_LIST toDeleteElement;
	toDeleteElement=getNode();
	toDeleteElement=listSearch(myListHead,6);
	int deletedElement=deleteNode(myListHead,toDeleteElement);
	
	printf("\nElementDeleted=%d\n",deletedElement);	
	printLinkedList(myListHead);
	


	return 0;
}
