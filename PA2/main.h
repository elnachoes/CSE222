#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_STATE 0
#define QUEUE_STATE 1

//how buffer space for user input
#define INPUT_BUFFER 1024

//the arbitrary magic number to set the sentinel node's data to because of the assignment
#define SENTINEL_DATA 1234567

//I made a macro just for this message for the sake of being a little bit cleaner just because it is so big
#define HELP_MESSAGE \
"Usage:\n\
 #            insert # into stack or queue\n\
 s            select STACK mode and display stack\n\
 <ENTER>      remove top of stack/head of queue and display\n\
 x            Quit\n\
 ?            Display help\n"


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
int queueRemove(myNode* queue);
int queueIsEmpty(myNode* queue);
void queuePrint(myNode* queue);

//queue/stack functions
void cleanup(myNode* stackorqueue);