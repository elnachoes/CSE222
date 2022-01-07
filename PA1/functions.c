#include "main.h"

//returns a ptr to a sentinal node
//auto sets the data of the sentinal node to be : 1234567
myNode *InitNode()
{
	myNode* sentinalNode = (myNode*)malloc(sizeof(myNode));
	sentinalNode->nextNode = NULL;
	sentinalNode->data = 1234567; // set to 1234567 due to instruction
	return sentinalNode;
}

int add(myNode* list, int number)
{

	myNode* newNode = (myNode*)malloc(sizeof(myNode));
	newNode->data = number;

	//null ptr check
	if (newNode == NULL)
		return 0;

	myNode* previousNode = NULL;
	myNode* currentNode = list->nextNode;

	if (currentNode->nextNode == NULL)
	{
		currentNode->nextNode = newNode;
		return 1;
	}

	while (true)
	{

	}

	return 1;
}