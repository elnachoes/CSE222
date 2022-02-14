#include "main.h"

//NOTE : DUPLICATES MIGHT BREAK THIS IF YOU TRY TO SHOVE IN A DUPLICATE
Node add(Node root, char *plate, char *first, char *last)
{
    if (root == NULL)
    {
        root = malloc(sizeof(Node));
        root->plate = malloc( sizeof(char) * (strlen(plate) + 1) );
        root->first = malloc( sizeof(char) * (strlen(first) + 1) );
        root->last = malloc( sizeof(char) * (strlen(last) + 1) );
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (strcmp(plate, root->plate) < 0)
    {
        root->left = add(root, plate, first, last);
        return root;
    }

    else if (strcmp(plate, root->plate) > 0)
    {
        root->right = add(root, plate, first, last);
        return root;
    }

    else
    {
        return root;
    }
}

int search(Node root, char *plate, char *first, char *last)
{
    return 1;
}


//LNR traversal free
void treeFree(Node root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root->plate);
            free(root->first);
            free(root->last);
            free(root);
            return;
        }
        else
        {
            Node temp = root;
            root = root->left;
            treeFree(root);
            root = root->right;
            treeFree(root);
            root = temp;
            treeFree(root);
            return;
        }
    }
}