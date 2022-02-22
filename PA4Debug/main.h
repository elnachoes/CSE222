#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//I thought this was in stdlib but it wasn't so I found it and just stuck it here
//I know its jankey but I saw it being used and I wanted to use it
#define max(a,b) (((a) > (b)) ? (a) : (b))

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
//void ReParent(Node Parent, Node Orphan);
Node ReParent(Node Parent, Node Orphan);
void LNR(Node root);
void LNR_debug(Node root);
void RNL(Node root);
void NLR(Node root);
void freeNode(Node root);
void treeFree(Node root);
