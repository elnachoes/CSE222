#include "main.h"

//returns a ptr to a sentinal node
//auto sets the data of the sentinal node to be : 1234567
myNode *init()
{
    myNode* sentinalNode = (myNode*)malloc(sizeof(myNode));
    sentinalNode->nextNode = NULL;
    sentinalNode->data = 1234567; // set to 1234567 due to instruction
    return sentinalNode;
}

int add(myNode* list, int number)
{
    //creating a pointer to a new myNode and setting its data equal to the int input
    myNode* newNode = (myNode*)malloc(sizeof(myNode));
    newNode->data = number;
    newNode->nextNode = NULL;


    //null ptr check
    if (newNode == NULL)
        return 0;

    //I start stepping through the linked list with the sentinal as the previous and it's next node as the current node
    myNode* previousNode = list;
    myNode* currentNode = list->nextNode;

    //edge case for if you put in your first myNode and the sentinal's next node is null just stick it in front of the sentinal
    if (currentNode == NULL)
    {
        previousNode->nextNode = newNode;
        return 1;
    }

    while (true)
    {
        //if the next node is null its at the end of the list and should either be put in front or behind the last node
        if (currentNode->nextNode == NULL)
        {
            if (currentNode->data >= newNode->data)
            {
                previousNode->nextNode = newNode;
                newNode->nextNode = currentNode;
            }
            else
            {
                currentNode->nextNode = newNode;
            }
            break;
        }
        //if the value for newNode-> is in between currentNode and Previous node slot newNode in between the previous node and the current node
        else if(currentNode->data >= newNode->data && previousNode->data <= newNode->data)
        {
            previousNode->nextNode = newNode;
            newNode->nextNode = currentNode;
            break;
        }
        //if neither of those conditions are met set the previous node to the current one and the current one to currentNode->nextNode
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
    }

    return 1;
}

void print(myNode* list)
{
    myNode* currentNode = list->nextNode;

    while (true)
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->nextNode;

        if (currentNode->nextNode == NULL)
        {
            printf("%d\n", currentNode->data);
            break;
        }
    }
}

int delete(myNode* list, int number)
{
    myNode* previousNode = list;
    myNode* currentNode = list->nextNode;

    while (true)
    {
        if (currentNode->data == number)
        {
            previousNode->nextNode = currentNode->nextNode;
            free(currentNode);
            return 1;
        }
        else if (currentNode->nextNode == NULL)
        {
            return 0;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
    }
}

int search(myNode* list, int number)
{
    myNode* currentNode = list->nextNode;

    while (true)
    {
        if (currentNode->data == number)
        {
            return 1;
        }
        else if (currentNode->nextNode == NULL)
        {
            return 0;
        }
        else
        {
            currentNode = currentNode->nextNode;
        }
    }
    return 0;
}

void cleanup(myNode* list)
{
    myNode* currentNode = list;
    myNode* nextNode = NULL;
    while (true)
    {
        if (currentNode->nextNode == NULL)
        {
            free(currentNode);
            return;
        }
        else
        {
            myNode* nextNode = currentNode->nextNode;
            free(currentNode);
            currentNode = nextNode;
        }
    }
}