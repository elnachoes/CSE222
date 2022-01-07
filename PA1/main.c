//Author : Corbin Martin
//TODO : ^^^^^^ fill the rest of this in later ^^^^^^


#include "main.h"

void TestPrint(myNode* list)
{
    myNode* currentNode = list->nextNode;

    while (true)
    {
        printf("%d\n", currentNode->data);
        currentNode = currentNode->nextNode;

        if (currentNode->nextNode == NULL)
        {
            printf("%d\n", currentNode->data);
            break;
        }
    }
}

void main()
{
    myNode* myList = InitNode();

    add(myList, 98);
    add(myList, 2);
    add(myList, 7);
    add(myList, 190);
    add(myList, 5);

    TestPrint(myList);

    return;
}
