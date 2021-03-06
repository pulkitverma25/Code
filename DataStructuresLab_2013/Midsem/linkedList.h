/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct node
{
	unsigned int key;
	int weight;
	struct node* next;
};
typedef struct node* LINKED_LIST;

int isListEmpty(LINKED_LIST head);
LINKED_LIST getNode();
LINKED_LIST listSearch(LINKED_LIST head,unsigned int element);
void insertAtHead(LINKED_LIST head, LINKED_LIST newNode);
void insertAfterNode(LINKED_LIST afterNode, LINKED_LIST newNode);
int deleteNode(LINKED_LIST head, LINKED_LIST nodeToDelete);
LINKED_LIST findLastNode(LINKED_LIST head);
void printLinkedList(LINKED_LIST head);

#endif
