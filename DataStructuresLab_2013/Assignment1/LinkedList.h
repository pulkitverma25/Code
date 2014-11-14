/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#endif

struct node
{
	unsigned int key;
	struct node* next;
};
typedef struct node* LINKED_LIST;

int isListEmpty(LINKED_LIST head)
{
	if(head==NULL || head->next==NULL)
	{
		return TRUE;
	}
	else
		return FALSE;
}

LINKED_LIST getNode()
{
	LINKED_LIST newNode;
	newNode=(LINKED_LIST)malloc(sizeof(struct node));
	
	return newNode;
}

LINKED_LIST listSearch(LINKED_LIST head, int element)
{
	int count=0;
	if(isListEmpty(head))
		return NULL;
	else
	{
		LINKED_LIST tempNode=getNode();
	
		tempNode=head->next;
		while(tempNode != NULL && tempNode->key!=element)
		{
			count++;
			tempNode=tempNode->next;
		}
		if(tempNode!=NULL)
			printf("\nPosition:%d\n",count+1);
		return tempNode;
	}
}

int findElementAtPosition(LINKED_LIST head, int position)
{
	int i,element;
	if(isListEmpty(head))
		return -1;
	else
	{
		LINKED_LIST tempNode=getNode();
		tempNode=head->next;
		for(i=1;i<position;i++)
		{
			if(tempNode!=NULL)
			{
				tempNode=tempNode->next;
			}
			else
			{
				printf("\nERROR:Position not found\n");
				return -1;
			}
		}
		
		element=tempNode->key;
		return element;
	}
}

void insertAtHead(LINKED_LIST head, LINKED_LIST newNode)
{
	newNode->next=head->next;
	head->next=newNode;
	
	return;
}

void insertAfterNode(LINKED_LIST afterNode, LINKED_LIST newNode)
{
	newNode->next=afterNode->next;
	afterNode->next=newNode;
	return;
}

void insertAtPosition(LINKED_LIST head, LINKED_LIST newNode, int position)
{
	int i;
	if(head==NULL)
		return;
	else
	{
		LINKED_LIST tempNode=getNode();
		tempNode=head;
		for(i=0;i<position-1;i++)
		{
			if(tempNode!=NULL)
			{
				tempNode=tempNode->next;
			}
			else
			{
				printf("\nERROR:Position not found\n");
				return ;
			}
		}
		newNode->next=tempNode->next;
		tempNode->next=newNode;		
		return ;
	}
}

int deleteNode(LINKED_LIST head, LINKED_LIST nodeToDelete)
{
	if(isListEmpty(head))
		return -1;
	else
	{
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
}

LINKED_LIST findLastNode(LINKED_LIST head)
{
	if(isListEmpty(head))
		return head;
	else
	{
		LINKED_LIST tempNode=getNode();
		tempNode=head;
		while(tempNode != NULL && tempNode->next!=NULL)
		{
			tempNode=tempNode->next;
		}
		return tempNode;
	}
}

void printLinkedList(LINKED_LIST head)
{
	if(isListEmpty(head))
		return;
	else{
	LINKED_LIST tempNode=getNode();
	tempNode=head->next;	
	while(tempNode != NULL)
	{
		printf("%d\t",tempNode->key);
		tempNode=tempNode->next;
	}
	printf("\n\n");
	}
	return;
}

