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

//pops the top of the stack off of the stack and returns its data value
int stackPop(myNode* stack)
{
    int returnVal = stack->nextNode->data;

    myNode* popItem = stack->nextNode;
    myNode* nextTOS = popItem->nextNode;

    free(popItem);

    stack->nextNode = nextTOS;

    return returnVal;
}

int stackIsEmpty(myNode* stack)
{
    if(stack->nextNode == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void stackPrint(myNode* stack)
{
    myNode* currentNode = stack->nextNode;

    printf("TOS-->");

    while(true)
    {
        printf("%d ",currentNode->data);

        if(currentNode->nextNode == NULL) break;

        currentNode = currentNode->nextNode;
    }
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


//this free's all the memory allocated by the stack/que
void cleanup(myNode* stackorqueue)
{
    myNode* currentNode = stackorqueue;
    myNode* nextNode = NULL;

    while (true)
    {
        //when your at the end of the list free the last node and exit
        if (currentNode->nextNode == NULL)
        {
            free(currentNode);
            return;
        }

        //set the nextNode first because we will free the current node after
        //once the current node is freed set the current node to the next node
        else
        {
            myNode* nextNode = currentNode->nextNode;
            free(currentNode);
            currentNode = nextNode;
        }
    }
}