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
    newNode->next = sent->next;
    sent->next = newNode;
}


int listFind(struct node* sent, char* plate, char* firstname, char* lastname)
{
    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        if (!strcmp(currentNode->plate,plate))
        {

            strcpy(firstname, currentNode->first);
            strcpy(lastname, currentNode->last);
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;
}


int listLen(struct node* sent)
{
    int length = 0;

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
        printf("Plate: <%s>  Name: %s, %s\n", currentNode->plate, currentNode->first, currentNode->last);
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