#pragma once


#define _CRT_SECURE_NO_WARNINGS
#define randMIN 10
#define randMAX 100
#define foreach(p,head) \
	for (Position p = head; p != NULL; p = p->next) 

#include <stdio.h>
#include <stdlib.h>

struct _stack;
typedef struct _stack* Stackpos;
typedef struct _stack {
	Position sDir;
	Stackpos next;
}Stack;


Stackpos createNode(Position);
int printList(Stackpos);

Position pop(Stackpos);
int push(Stackpos, Stackpos);