#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//how buffer space for user input
#define INPUT_BUFFER 1024

//linked list node
typedef struct myNode
{
	int data;
	struct myNode* nextNode;
} myNode;

//stack functions
myNode* stackInit();
void stackPush(myNode* stack, int num);
int stackPop(myNode* stack);
int stackIsEmpty(myNode* stack);
void stackPrint(myNode* stack);

//queue functions
myNode* queueInit();
void queueAdd(myNode* queue, int num);
void queueRemove(myNode* queue);
int queueIsEmpty(myNode* queue);
void queuePrint(myNode* queue);

//queue/stack functions
void cleanup(myNode* stackorqueue);