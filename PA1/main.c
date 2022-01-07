#include <stdio.h>
#include "main.h"

void TestPrint(myNode* list)
{
	myNode* currentNode = list;

	while (currentNode->nextNode != NULL)
	{
		printf("%d\n", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}

void main()
{
	myNode* myList = InitNode();

	add(myList, 5);

	printf("%d", myList->data);

	// TestPrint(linkedList);

	// printf("asdf");

	// printf("%d", linkedList->data);

	return;
}
