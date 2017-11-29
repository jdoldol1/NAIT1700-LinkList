#pragma once	
#include "node.h"


//Stack Functions
Node * Push(Node * head, int val);
Node * Delete(Node * head);
Node * InsertInOrder(Node * head, int val);
void PrintList(Node * head);
Node * InsertAfter(Node * loc, int val);
Node * Pop(Node * head, int * pop);

