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

//goes through the and prints the left node, the node, and the right node in an LNR traversal
void LNR(Node root)
{
    if (!root) return;
    LNR(root->left);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
    LNR(root->right);
}

//goes through the and prints the the node, the left node, and right node in an LNR traversal
void NLR(Node root)
{
    if (!root) return;
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
    NLR(root->left);
    NLR(root->right);
}

//goes through the and prints the left node, right node and then the node in an LNR traversal
void LRN(Node root)
{
    if (!root) return;
    LRN(root->left);
    LRN(root->right);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
}


//this deletes a specific node BUT preserves the children of the deleted node
Node delete(Node root, char* plate)
{
    if (root == NULL) return NULL;

    // if the left node isn't null check if it is the node you want to delete
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
    // if the right node isn't null check if it is the node you want to delete
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
    // if the right node isn't null check if it is the node you want to delete
    if (strcmp(root->plate, plate) == 0)
    {
        Node newParent = ReParent(root->right, root->left);
        freeNode(root);
        root = newParent;
    }
    return root;
}

//this takes in a parent and an orphan and orders the hierarchy accordingly 
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

//this frees a specific node which is used in delete and treeFree
void freeNode(Node root)
{
    free(root->plate);
    free(root->first);
    free(root->last);
    free(root);
}

//LNR traversal free
void treeFree(Node root)
{
    if (!root) return;
    treeFree(root->left);
    treeFree(root->right);
    freeNode(root);
}


Node LoadDatabase(char* database)
{
    Node root = NULL;
    FILE* fileHandle = fopen(database, "r");
    if (fileHandle == NULL)
    {
        printf("ERROR Cannot open %s\r\n", database);
        return NULL;
    }

    char chunk[1000];
    char plate[257];
    char first[257];
    char last[257];

    while (fgets(chunk, sizeof(chunk), fileHandle) != NULL)
    {
        sscanf(chunk, "%s%s%s", plate, first, last);
        root = add(root, plate, first, last);
    }
    fclose(fileHandle);

    return root;
}