#include "main.h"

//linked list constructor
node* listInit()
{
    node* newSentinal = malloc(sizeof(node));
    newSentinal->plate = SENT_DATA;
    newSentinal->first = SENT_DATA;
    newSentinal->last = SENT_DATA;
    newSentinal->next = NULL;
    return newSentinal;
}


void listAdd(struct node *sent, char* plate, char* firstname, char* lastname)
{
    node* newNode = malloc(sizeof(node));
    newNode->plate = plate;
    newNode->first = firstname;
    newNode->last = lastname;
    newNode->next = NULL;

    node* currentNode = sent;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}


int listFind(struct node* sent, char* plate, OUT_PARAMETER char* firstname, OUT_PARAMETER char* lastname)
{
    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        if (currentNode->plate == plate)
        {
            firstname = currentNode->first;
            lastname = currentNode->last;
            return 1;
        }
        currentNode = currentNode->next;
    }

    return 0;
}


int listLen(struct node* sent)
{
    int length;

    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        ++length;
        currentNode = currentNode->next;
    }

    return length;
}


void listPrint(struct node* sent)
{
    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        printf("Plate: <%s>  Name: %s, %s", currentNode->plate, currentNode->first, currentNode->first);
        currentNode = currentNode->next;
    }
}


void listFree(struct node* sent)
{
    node* currentNode = sent;
    node* nextNode = NULL;

    while (true)
    {
        if (currentNode->next == NULL)
        {
            free(currentNode);
            return;
        }
        else
        {
            node* nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
    }
}