#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//these are used to get rid of magic numbers for switching states in the main program
#define STACK_STATE 0

#define QUEUE_STATE 1

//how buffer space for user input
#define INPUT_BUFFER 1024

//the arbitrary magic number to set the sentinel node's data to because of the assignment
#define SENTINEL_DATA 1234567

//I made a macros just for these strings for the sake of being a little bit cleaner just because they are so big
#define WELCOME_MESSAGE "Welcome. This program demonstrates the use of a stack and a queue.\n"

#define HELP_MESSAGE \
"Usage:\n\
 #            insert # into stack or queue\n\
 s            select STACK mode and display stack\n\
 q            select QUEUE mode and display queue\n\
 <ENTER>      remove top of stack/head of queue and display\n\
 x            Quit\n\
 ?            Display help\n"

//linked list node (same thing in both the stack and queue)
typedef struct myNode
{
	int data;
	struct myNode* nextNode;
} myNode;

// ---- ALL of the below functions are defined in functions.c ----

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