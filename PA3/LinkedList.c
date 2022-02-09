#include "main.h"

//linked list constructor
node* listInit()
{
    node* newSentinal = malloc(sizeof(node));
    newSentinal->plate = NULL;
    newSentinal->first = NULL;
    newSentinal->last = NULL;
    newSentinal->next = NULL;
    return newSentinal;
}

//adds a new list item by allocating exactly as much space as needed for the node and input strings
//also appends the new item to the front of the linked list
void listAdd(struct node* sent, char* plate, char* firstname, char* lastname)
{
    node* newNode = malloc(sizeof(node));
    newNode->plate = malloc( sizeof(char) * (strlen(plate) + 1) );
    strcpy(newNode->plate,plate);
    newNode->first = malloc( sizeof(char) * (strlen(firstname) + 1) );
    strcpy(newNode->first,firstname);
    newNode->last = malloc( sizeof(char) * (strlen(lastname) + 1) );
    strcpy(newNode->last,lastname);
    newNode->next = sent->next;
    sent->next = newNode;
}

//finds a item inside the linked list and stores the firstname and last name in the input variables if found
//returns a 1 if found and a 0 if not found
int listFind(struct node* sent, char* plate, char* firstname, char* lastname)
{
    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        if (!strcmp(currentNode->plate, plate))
        {

            strcpy(firstname, currentNode->first);
            strcpy(lastname, currentNode->last);
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

//returns the length of the list
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

//prints the contents of the list
void listPrint(struct node* sent)
{
    node* currentNode = sent->next;

    while (currentNode != NULL)
    {
        printf("Plate: <%s>  Name: %s, %s\n", currentNode->plate, currentNode->last, currentNode->first);
        currentNode = currentNode->next;
    }
}

//frees all elements in the list and the dynamically allocated strings stored in it
void listFree(struct node* sent)
{
    node* currentNode = sent;

    while (currentNode != NULL)
    {
        node* next = currentNode->next;

        if (currentNode->plate != NULL) free(currentNode->plate);
        if (currentNode->first != NULL) free(currentNode->first);
        if (currentNode->last != NULL) free(currentNode->last);

        free(currentNode);
        currentNode = next;
    }
}