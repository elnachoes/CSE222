#include "main.h"


// ------------STACK FUNCTIONS------------


//this function returns a ptr to a sentinel node of a stack
myNode *stackInit()
{
    myNode* sentinelNode = malloc(sizeof(myNode));
    sentinelNode->nextNode = NULL;

    //set to the magic number 1234567 to avoid valgrind errors (the sentinal isn't used for data anyway)
    sentinelNode->data = SENTINEL_DATA;;

    return sentinelNode;
}

//LIFO (last in first out) structure
//this function adds a new item to the top of the stack and moves the next items behind the top of the stack
//the TOS gets inserted as the first element so when the stack gets popped it will just pull of the first element in the linked list that isn't the sentinel
void stackPush(myNode* stack, int num)
{
    myNode* newNode = malloc(sizeof(myNode));

    newNode->data = num;
    newNode->nextNode = stack->nextNode;

    stack->nextNode = newNode;
}

//this function pops the top of the stack off of the stack and returns its data value
//since the TOS is the first element after the sentinel it will just pull off the first element
//WATCH OUT WILL DEREFERENCE A NULL PTR IF THE STACK IS EMPTY
int stackPop(myNode* stack)
{
    int returnVal = stack->nextNode->data;

    myNode* popItem = stack->nextNode;
    myNode* nextTOS = popItem->nextNode;

    free(popItem);

    stack->nextNode = nextTOS;

    return returnVal;
}

//this function returns a 1 if the stack is empty or a 0 if the stack is not empty
int stackIsEmpty(myNode* stack)
{
    if(stack->nextNode == NULL)
        return 1;
    else
        return 0;
}

//this function prints the stack in order from TOS to the bottom of the stack
//WATCH OUT WILL DEREFERENCE A NULL PTR IF THE STACK IS EMPTY
void stackPrint(myNode* stack)
{
    myNode* currentNode = stack->nextNode;

    printf("TOS-->");   //prints specifically "TOS-->" as instructed

    if(currentNode != NULL)
    {
        while(true)
        {
            printf("%d ",currentNode->data);

            if(currentNode->nextNode == NULL)
                break;

            currentNode = currentNode->nextNode;
        }
    }
}


// ------------QUEUE FUNCTIONS------------


//this function returns a ptr to a sentinel node of a queue
myNode *queueInit()
{
    myNode* sentinelNode = malloc(sizeof(myNode));
    sentinelNode->nextNode = NULL;

    //set to the magic number 1234567 to avoid valgrind errors (the sentinal isn't used for data anyway)
    sentinelNode->data = SENTINEL_DATA;

    return sentinelNode;
}

//FIFO (first in first out) structure
//this function adds a new item to the tail of a queue so that it will get removed last in order from the head to tail
void queueAdd(myNode* stack, int num)
{
    myNode* newNode = malloc(sizeof(myNode));
    myNode* currentNode = stack;

    //walk to the tail of the queue then add the new item
    while(currentNode->nextNode != NULL)
    {
        currentNode = currentNode->nextNode;
    }

    newNode->nextNode = NULL;
    newNode->data = num;

    currentNode->nextNode = newNode;
}

//this function removes the head of the queue
//WATCH OUT WILL DEREFERENCE A NULL PTR IF THE QUEUE IS EMPTY
int queueRemove(myNode* queue)
{
    myNode* head = queue->nextNode;
    int returnValue = head->data;

    queue->nextNode = head->nextNode;

    free(head);

    return returnValue;
}

//this function returns a 1 if the queue is emtpy and a 0 if it is not empty
int queueIsEmpty(myNode* queue)
{
    if(queue->nextNode == NULL)
        return 1;
    else
        return 0;
}

//this function prints the contents of the queue out from head to tail
//WATCH OUT WILL DEREFERENCE A NULL PTR IF THE QUEUE IS EMPTY
void queuePrint(myNode* queue)
{
    myNode* currentNode = queue->nextNode;

    printf("HEAD--> "); //prints specifically "HEAD--> " as instructed

    if(currentNode != NULL)
    {
        while(true)
        {
            printf("%d ",currentNode->data);

            if(currentNode->nextNode == NULL)
                break;

            currentNode = currentNode->nextNode;
        }
    }

    printf("<--TAIL");  //prints specifically "<--TAIL" as instructed
}


// ------------QUEUE/STACK FUNCTIONS------------


//this function free's all the memory allocated by the stack/que
//this acts as a destructor for ANY linked list structure given a pointer to the sentinal so it works on BOTH the stack and queue
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