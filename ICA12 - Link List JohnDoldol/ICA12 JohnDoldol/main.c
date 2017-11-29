#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "queue.h"

int main(int argc, char ** argv)
{
	srand((unsigned int)time(NULL));

	printf(" Linked List Stack Test \n");

	Node * head = NULL;
	int popListVal = 0;

	for (int i = 0; i < 10; ++i)
		head = Push(head, rand() % 100);
	PrintList(head);

	printf("ListPush integer 420 to list: \n");
	head = Push(head, 420);
	PrintList(head);


	Node * currPOP = head;
	while (currPOP)
	{
		currPOP = Pop(currPOP, &popListVal);
		printf("Dequeue integer from ListPop function: %d\n", popListVal);
	}
	head = currPOP;

	//head = ListPop(head, &popListVal);
	//printf("Poped integer from ListPop function: %d\n", popListVal);
	PrintList(head);
	head = Delete(head);

	printf(" Linked List Queue Test \n");
	int dequeListVal = 0;

	for (int i = 0; i < 10; ++i)
		head = Enqueue(head, rand() % 100);
	PrintList(head);

	printf("ListEnque integer 99 to list: \n");
	head = Enqueue(head, 420);
	PrintList(head);

	Node * currDQ = head;
	while (currDQ)
	{
		currDQ = Dequeue(currDQ, &dequeListVal);
		printf("Dequeue integer from ListDeque function: %d\n\n", dequeListVal);
		PrintList(currDQ);
	}
	head = currDQ;

	for (int i = 0; i < 10; ++i)
	{
		printf("ListEnque integer 42%d to list: \n", i);
		head = Enqueue(head, 99 + i);
		PrintList(head);
	}
	//}
	//head = ListDeque(head, &dequeListVal);
	//printf("Dequeue integer from ListDeque function: %d\n", dequeListVal);
	//PrintList(head);

	head = Delete(head);
	getchar();

	fflush(stdout);
	//Press enter to not make debug window go away
#ifdef _DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
	printf("Press Enter to Exit");
	fgetc(stdin);
#endif
	return EXIT_SUCCESS;
}

////own test code
//Node * head = NULL;
//srand((unsigned int)time(NULL));

////create an oredered list
//for (int i = 0; i < 10; ++i)
//	head = InsertInOrder(head, rand() % 100);
//printf("Stack(Linked List)\n");
//PrintList(head);
//
////push sequence
//int value;
//printf("\nEnter value to PUSH in stack: ");
//scanf("%d", &value);
//
//head = Push(head, value);
//PrintList(head);
//
////Pop sequence
//printf("\nPop: ");
//
////list will pop head value; head will 
////create popped node
//int pop;
//head = Pop(&pop, head);
//printf("%d\n", pop);
//PrintList(head);
//
////QUEUE Add or ENQUEUE
//printf("\nEnter value to ENQUEUE in QUEUE: ");
//scanf("%d", &value);
//head = Enqueue(head, value);
//PrintList(head);
//
////DEQUEUE
//printf("\nDeQueue: ");
////Node * curr = head;	
//
//while (head)
//{
//	head = Dequeue(head, &pop);
//	printf("%d\n", pop);
//	PrintList(head);
//}