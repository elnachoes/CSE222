#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct myNode
{
	int data;
	struct myNode* nextNode;
} myNode;

myNode* InitNode();
int add(myNode* list, int number);
int delete(myNode* list, int number);
void print(myNode* list);
void cleanup(myNode* list);

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
