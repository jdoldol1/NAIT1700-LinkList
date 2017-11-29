#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void PrintList(Node * head)
{
	while (head)
	{
		printf("%d->", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

Node * Push(Node * head, int val)
{
	//create new node
	Node * temp = (Node*)malloc(sizeof(Node));
	//input pushed value to temp
	temp->val = val;
	temp->next = NULL;
	//if list does not exist
	if (!head)
		return temp;

	//point temp to head
	temp->next = head;
	
	//return temp as new head in main	
	return temp;
}
Node * Pop(Node * head, int * pop)
{
	if (!head)
		return head;
	if (head->next == NULL)
	{
		*pop = head->val;
		return NULL;
	}

	//set val to current head value via pointer reference
	* pop = head->val;

	//set next head to new head return
	return head->next;
}
Node * Delete(Node * head)
{
	Node * curr = head;
	while (curr)
	{
		curr = head->next;
		free(head);
		head = curr;
	}
	return NULL;
}

Node * InsertAfter(Node * loc, int val)
{
	//I'm going to a new node
	Node * new = (Node *)malloc(sizeof(Node));
	new->val = val;
	new->next = NULL;
	if (!loc) return new;

	new->next = loc->next;
	loc->next = new;
	return loc;
}
//Insert an item before the first item greater than
//its value
Node * InsertInOrder(Node * head, int val)
{
	//Find the node BEFORE the first node greater than val.
	//First case, empty list.

	if (!head) return (InsertAfter(NULL, val));

	//Second case, insert at head.
	if (head->val > val)
	{
		Node * new = (Node *)malloc(sizeof(Node));
		new->val = val;
		new->next = head;
		return new;
	}

	//Otherwise, just find my insertion point.
	Node * curr = head;
	//Check the value of the node after my current node
	//Take advantage of lazy evaluation to only check next val
	//if next exists.
	while (curr->next && curr->next->val < val) curr = curr->next;
	//At insertion pont
	InsertAfter(curr, val);
	return head;
}