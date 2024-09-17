#include <stdio.h>
#include <stdlib.h>

typedef struct Info Info;

typedef struct {
	Info *info;
} Stack;


// O(1)

Stack initStack();

// O(1)

int getSize(Stack s);

// O(1)

void * peekStack(Stack s);

// O(1)

int pushStack(Stack s, void *data);

// O(1)

void * popStack(Stack s);

// O(n)

void * getAtIndex(Stack s, int index);

// O(n)

void freeStack(Stack s);
