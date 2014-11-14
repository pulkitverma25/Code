/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _LINKEDLISTNEW
#include <stdio.h>
#include "LinkedList.h"
#endif


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
	if(searchElement==NULL)
		return -1;

	printf("\n\nSearchedElement:%d\n",searchElement->key);

	LINKED_LIST lastNode;
	lastNode=getNode();

	lastNode=findLastNode(myListHead);	
	if(lastNode==NULL)
		return -1;
	printf("\n\nLastNode:%d\n",lastNode->key);

	LINKED_LIST newNodeAtPosition;
	newNodeAtPosition=getNode();
	newNodeAtPosition->key=133;
	insertAtPosition(myListHead,newNodeAtPosition,6);
	printLinkedList(myListHead);

	LINKED_LIST toDeleteElement;
	toDeleteElement=getNode();
	toDeleteElement=listSearch(myListHead,6);
	int deletedElement=deleteNode(myListHead,toDeleteElement);
	if(deletedElement==-1)
		printf("ERROR");
	else
		printf("\nElementDeleted=%d\n",deletedElement);	
	printLinkedList(myListHead);
	
	LINKED_LIST newNode;
	newNode=getNode();
	newNode->key=33;
	insertAfterNode(myListHead,newNode);
	printLinkedList(myListHead);
	

	return 0;
}
