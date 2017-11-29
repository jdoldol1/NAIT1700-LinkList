#pragma once
#include "node.h"

//Queue functions
Node * Enqueue(Node * head, int val);
Node * GetLast(Node * head);
Node * PreLast(Node * head);
Node * Dequeue(Node * head, int * val);