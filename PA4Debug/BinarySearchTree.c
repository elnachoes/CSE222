#include "main.h"

//NOTE : DUPLICATES MIGHT BREAK THIS IF YOU TRY TO SHOVE IN A DUPLICATE
Node add(Node root, char *plate, char *first, char *last)
{
    if (root == NULL)
    {
        root = malloc(sizeof(node));
        root->plate = malloc( sizeof(char) * (strlen(plate) + 1) );
        root->first = malloc( sizeof(char) * (strlen(first) + 1) );
        root->last = malloc( sizeof(char) * (strlen(last) + 1) );

        strcpy(root->plate,plate);
        strcpy(root->first,first);
        strcpy(root->last,last);
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    else if (strcmp(plate, root->plate) < 0)
    {
        root->left = add(root->left, plate, first, last);
        return root;
    }
    else if (strcmp(plate, root->plate) > 0)
    {
        root->right = add(root->right, plate, first, last);
        return root;
    }
    else
    {
        return root;
    }
}

//searches the tree and if it finds a node with the same plate, it will return a 1 and the first and last of the node in the out params
int search(Node root, char *plate, char *first, char *last)
{
    if (!root)
    {
        return 0;
    }

    if (!strcmp(root->plate,plate))
    {
        strcpy(first, root->first);
        strcpy(last, root->last);
        return 1;
    }

    if (search(root->left, plate, first, last))
    {
        return 1;
    }

    return search(root->right, plate, first, last);
}


int height(Node root)
{



    return 1;
}



//goes through the and prints the left node, right node and then the node in an LNR traversal
void LNR(Node root)
{
    if (!root) return;
    LNR(root->left);
    LNR(root->right);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
}

//goes through the and prints the right node, left node and then the node in an LNR traversal
void RNL(Node root)
{
    if (!root) return;
    RNL(root->right);
    RNL(root->left);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
}


//goes through the and prints the left node, right node and then the node in an LNR traversal
void NLR(Node root)
{
    if (!root) return;
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
    NLR(root->left);
    NLR(root->right);
}


//LNR traversal free
void treeFree(Node root)
{
    if (!root) return;
    treeFree(root->left);
    treeFree(root->right);
    free(root->plate);
    free(root->first);
    free(root->last);
    free(root);
}