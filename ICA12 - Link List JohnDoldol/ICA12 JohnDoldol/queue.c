#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node * Enqueue(Node * head, int val)
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

Node * GetLast(Node * head)
{
	//find end of list	
	Node * curr = head;
	//while curr points to something. set curr to the next pointed location
	while (curr->next) curr = curr->next;
	return curr;
}

Node * PreLast(Node * head)
{
	Node * curr;
	Node * last;
	curr = head;
	last = GetLast(head);

	//while my curr doesnt point to the last location, set curr to next location	
	while (curr->next != last)
	{
		curr = curr->next;
	}
	return curr;
}

Node * Dequeue(Node * head, int * val)
{
	//or should i return an int only?
	//Node * pop = (Node *)malloc(sizeof(Node));
	Node * last;
	if (!head)
		return head;
	if (head->next == NULL)
	{
		*val = head->val;
		return NULL;
	}
	
	//pop off the tail
	* val = GetLast(head)->val;

	//set second last as new last 
	last = PreLast(head);
	last->next = NULL;
	//free(head);
	return head;
}