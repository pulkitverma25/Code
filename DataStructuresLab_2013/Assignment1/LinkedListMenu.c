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
	int i,choice,exitButton=-1,tempNumber1,tempNumber2;
	LINKED_LIST myListHead,tempNode,lastNode;
	do
	{
		system("clear");		
		printf("\nMENU\n");
		printf("1. Create Linked List\n");
		printf("2. Add Element at end\n");
		printf("3. Add Element At Position\n");
		printf("4. Search Element\n");
		printf("5. Delete Element\n");
		printf("6. Find Last Element\n");
		printf("7. Exit\n");

		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				myListHead=getNode();
				myListHead->next=NULL;
				printf("\nLinked List Created\n");
				break;
			
			case 2:
				tempNode=getNode();
				printf("\nEnter the element you want to enter:");
				scanf("%d",&tempNumber1);
				tempNode->key=tempNumber1;
				lastNode=findLastNode(myListHead);
				insertAfterNode(lastNode,tempNode);
				printLinkedList(myListHead);
				break;

			case 3:
				tempNode=getNode();
				printf("\nEnter the position: ");
				scanf("%d",&tempNumber1);
				printf("\nEnter the element you want to enter: ");
				scanf("%d",&tempNumber2);
				tempNode->key=tempNumber2;
				insertAtPosition(myListHead, tempNode, tempNumber1);
				printLinkedList(myListHead);
				break;

			case 4:
				tempNode=getNode();
				printf("\nEnter the element you want to search: ");
				scanf("%d",&tempNumber2);
				printLinkedList(myListHead);
				tempNode=listSearch(myListHead,tempNumber2);	
				if(tempNode==NULL)
					printf("\nElement not found.\n");

				break;

			case 5:
				tempNode=getNode();
				printf("\nEnter the element you want to delete: ");
				scanf("%d",&tempNumber1);			
				tempNode=listSearch(myListHead,tempNumber1);
				tempNumber2=deleteNode(myListHead,tempNode);
				if(tempNumber2==-1)
					printf("\nData Not Found\n");
				else
					printf("\nElementDeleted=%d\n",tempNumber2);	
				printLinkedList(myListHead);
				break;

			case 6:	
				tempNode=findLastNode(myListHead);	
				if(tempNode!=myListHead)
					printf("\n\nLastNode:%d\n",tempNode->key);
				else
					printf("Data Not Found");
				printLinkedList(myListHead);
				break;

			case 7:
				exit(0);

		};		
		printf("\nEnter 0 to proceed: ");
		scanf("%d",&exitButton);																	
	}while(choice!=7 || exitButton!=0);
	

	return 0;
}
