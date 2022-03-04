#include "main.h"

// this adds a new node to a tree and returns the root of the tree
Node add(Node root, char *plate, char *first, char *last)
{
    // when the recursion lands on null make a new node and return the root
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
    // if the plate is lesser than the current plate recurse to the left
    else if (strcmp(plate, root->plate) < 0)
    {
        root->left = add(root->left, plate, first, last);
        return root;
    }
    // if the plate is greater than the current plate recurse to the right
    else if (strcmp(plate, root->plate) > 0)
    {
        root->right = add(root->right, plate, first, last);
        return root;
    }
    // if you run into a duplicate toss it out, duplicates would break the inherrent structure here
    else
    {
        return root;
    }
}

//searches the tree and if it finds a node with the same plate, it will return a 1 and the first and last of the node in the out params
int search(Node root, char *plate, char *first, char *last)
{
    if (root == NULL) return 0;

    // if it finds the string copy the first and last name into
    if (strcmp(root->plate,plate) == 0)
    {
        strcpy(first, root->first);
        strcpy(last, root->last);
        return 1;
    }

    // if the root is found on the left side return a 1
    if (search(root->left, plate, first, last)) return 1;

    // if the root is found on the right return a 1
    return search(root->right, plate, first, last);
}

//finds the maximum height of a tree
int height(Node root)
{
    // if you get to the bottom of the tree the height of the tree is -1
    if (root == NULL) return -1;
    // the height of the tree will always be one more than the left or the right nodes of a root
    return 1 + max(height(root->left), height(root->right));
}

//checks to see if a tree is balanced or not
int balanced(Node root)
{
    // if the root is null 
    if (root == NULL) return 1;
    // if both the left and right are balanced and the difference between the left heigth and right height is no greater than 1
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
//(pre order)
void NLR(Node root)
{
    if (!root) return;
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
    NLR(root->left);
    NLR(root->right);
}

//goes through the and prints the left node, right node and then the node in an LNR traversal
//(post order)
void LRN(Node root)
{
    if (!root) return;
    LRN(root->left);
    LRN(root->right);
    printf("Plate: <%s> Name: %s,%s\r\n", root->plate, root->last, root->first);
}

// this deletes a node from a tree and organizes it to a specific algorithm detailed in the assignment 
Node delete(Node root, char* plate)
{
    //case 1 the root is null return null
    if (root == NULL) return NULL;

    //if the plate is less than the root plate recurse left
    if (strcmp(root->plate, plate) > 0)
    {
        root->left = delete(root->left, plate);
        return root;
    }
    //if the plate is greater than the root plate recurse right
    else if (strcmp(root->plate, plate) < 0)
    {
        root->right = delete(root->right, plate);
        return root;
    }
    else
    {
        //case 2 both roots of the 
        if (root->left == NULL && root->right == NULL)
        {
            freeNode(root);
            return NULL;
        }

        //case 3 the root only has one right node
        else if (root->right == NULL)
        {
            Node temp = root->left;
            root->left = NULL;
            root->right = NULL;
            freeNode(root);
            return temp;
        }

        //case 4 the root only has one right node
        else if (root->left == NULL)
        {
            Node temp = root->right;
            root->left = NULL;
            root->right = NULL;
            freeNode(root);
            return temp;
        }
        //case 5 the root's left subtree's biggest node is the root's left node and the root has a right node
        else if (root->left->right == NULL)
        {
            Node temp = root->left;
            temp->right = root->right;
            root->left = NULL;
            root->right = NULL;
            freeNode(root);
            return temp;
        }
        //case 6 the root's left node has more nodes to the right of it along with a right node on the root
        else
        {
            Node previous = root->left;
            Node current = previous->right;

            while (current->right != NULL)
            {
                previous = current;
                current = current->right;
            }

            previous->right = current->left;
            current->left = root->left;
            current->right = root->right;

            root->left = NULL;
            root->right = NULL;

            freeNode(root);

            return current;
        }
    }
}

//LNR traversal free
void treeFree(Node root)
{
    if (!root) return;
    treeFree(root->left);
    treeFree(root->right);
    freeNode(root);
}

//this frees a specific node which is used in delete and treeFree
void freeNode(Node root)
{
    free(root->plate);
    free(root->first);
    free(root->last);
    free(root);
}

//this conveniently loads in my database and passes back a loaded up tree
Node LoadDatabase(char* database)
{
    Node root = NULL;
    FILE* fileHandle = fopen(database, "r");
    if (fileHandle == NULL)
    {
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