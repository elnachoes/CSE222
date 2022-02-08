#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

///---- LINKED LIST STUFF ----///
#define SENT_DATA ""

typedef struct node
{
    char* plate;
    char* first;
    char* last;
    struct node* next;
} node;

typedef struct node* hashEntry;

///---- LINKED LIST FUNCTIONS ----///
node* listInit();
void listAdd(struct node *sent, char* plate, char* firstname, char* lastname);
int listFind(struct node* sent, char* plate, char* firstname, char* lastname);
int listLen(struct node* sent);
void listPrint(struct node* sent);
void listFree(struct node* sent);


///---- HASHTABLE FUNCTIONS ----///
hashEntry *hashInit(int hashsize);
int hash(char* plate);
void hashAdd(hashEntry* hashTable, char* plate, char* first, char* last);
int hashFind(hashEntry* hashTable, char* plate, char* first, char* last);
void hashLoad(hashEntry* hashTable);
void hashDump(hashEntry* hashTable, int cellNum);
void hashFree(hashEntry* hashTable);


///---- MAIN FUNCTIONS ----///
void hashDatabase();