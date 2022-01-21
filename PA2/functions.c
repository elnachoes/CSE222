#include "main.h"

// ------------STACK FUNCTIONS------------


//this function returns a ptr to a sentinel node of a stack
myNode *stackInit()
{
    myNode* sentinelNode = malloc(sizeof(myNode));
    sentinelNode->nextNode = NULL;

    //set to the magic number 1234567 to avoid valgrind errors
    sentinelNode->data = SENTINEL_DATA;;

    return sentinelNode;
}

//
//LIFO (last in first out) structure
void stackPush(myNode* stack, int num)
{
    myNode* newNode = malloc(sizeof(myNode));

    newNode->data = num;
    newNode->nextNode = stack->nextNode;

    stack->nextNode = newNode;
}


// ------------QUEUE FUNCTIONS------------

//this function returns a ptr to a sentinel node of a queue
myNode *queueInit()
{
    myNode* sentinelNode = malloc(sizeof(myNode));
    sentinelNode->nextNode = NULL;

    //set to the magic number 1234567 to avoid valgrind errors
    sentinelNode->data = SENTINEL_DATA;

    return sentinelNode;
}

//
//FIFO (first in first out) structure
void queueAdd(myNode* stack, int num)
{

}


// ------------QUEUE/STACK FUNCTIONS------------