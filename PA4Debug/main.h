#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void LNR(Node root);
void NLR(Node root);
void LRN(Node root);
void treeFree(Node root);