#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//I thought this was in stdlib but it wasn't so I found it and just stuck it here
//I know its jankey but I saw it being used and I wanted to use it
#define max(a,b) (((a) > (b)) ? (a) : (b))

#define STRING_BUFFER 1000

typedef struct node{
    char *plate;
    char *first;
    char *last;
    struct node *left;
    struct node *right;
} node;

typedef struct node* Node;

int height(Node root);
int balanced(Node root);
int search(Node root, char *plate, char *first, char *last);

Node add(Node root, char *plate, char *first, char *last);
Node delete(Node root, char *plate);
Node LoadDatabase(char* database);

void LNR(Node root);
void NLR(Node root);
void LRN(Node root);
void freeNode(Node root);
void treeFree(Node root);