#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///---- LINKED LIST STUFF ----///
#define SENT_DATA ""


#define OUT_PARAMETER


typedef struct node
{
    char* plate;
    char* first;
    char* last;
    struct node* next;
} node;

///---- PUBLIC FUNCTIONS ----///
node* listInit();
void listAdd(struct node *sent, char* plate, char* firstname, char* lastname);
int listFind(struct node* sent, char* plate, char* firstname, char* lastname);
int listLen(struct node* sent);
void listPrint(struct node* sent);
void listFree(struct node* sent);

///---- PRIVATE FUNCTIONS ----///
node* TraverseList(int index);
node* TraverseListToEnd();