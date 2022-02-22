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
    if (root == NULL) return 0;

    if (strcmp(root->plate,plate) == 0)
    {
        first = root->first;
        last = root->last;
        return 1;
    }

    if (search(root->left, plate, first, last)) return 1;

    return search(root->right, plate, first, last);
}

//finds the maximum height of a tree
int height(Node root)
{
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

//checks to see if a tree is balanced or not
int balanced(Node root)
{
    if (root == NULL) return 1;
    return (balanced(root->right) && balanced(root->right) && abs(height(root->left) - height(root->right)) <= 1) ? 1 : 0;
}

//goes through the and prints the left node, right node and then the node in an LNR traversal
void LNR(Node root)
{
    if (!root) return;
    LNR(root->left);
    LNR(root->right);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
}

//goes through the and prints the left node, right node and then the node in an LNR traversal
void LNR_debug(Node root)
{
    if (!root) return;
    LNR_debug(root->left);
    LNR_debug(root->right);
    printf(" <%s> ", root->plate);
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
    freeNode(root);
}

//UNFINISHED
Node delete(Node root, char* plate)
{
    if (root == NULL) return NULL;

    if (root->left != NULL)
    {
        if (strcmp(root->left->plate,plate) == 0)
        {
            Node newParent = ReParent(root->left->right, root->left->left);
            freeNode(root->left);
            root->left = newParent;
            return root;

        }
        else
        {
            root->left = delete(root->left, plate);
        }
    }
    if (root->right != NULL)
    {
        if (strcmp(root->right->plate, plate) == 0)
        {
            Node newParent = ReParent(root->right->right, root->right->left);
            freeNode(root->right);
            root->right = newParent;
            return root;

        }
        else
        {
            root->right = delete(root->right, plate);
        }
    }
    if (strcmp(root->plate, plate) == 0)
    {
        Node newParent = ReParent(root->right, root->left);
        freeNode(root);
        root = newParent;
        return root;
    }
    return root;
}

Node ReParent(Node Parent, Node Orphan)
{
    if (Orphan == NULL) return Parent;

    if (Parent == NULL && Orphan != NULL) return Orphan;

    if (Parent->left == NULL && strcmp(Parent->plate, Orphan->plate) > 0)
    {
        Parent->left = Orphan;
        return Parent;
    }
    else if (Parent->right == NULL && strcmp(Parent->plate, Orphan->plate) < 0)
    {
        Parent->right = Orphan;
        return Parent;
    }
    else
    {
        if (strcmp(Parent->plate, Orphan->plate) > 0)
        {
            Parent->left = ReParent(Parent->left, Orphan);
            return Parent;
        }
        else
        {
            Parent->right = ReParent(Parent->right, Orphan);
            return Parent;
        }
    }
}


void freeNode(Node root)
{
    free(root->plate);
    free(root->first);
    free(root->last);
    free(root);
}