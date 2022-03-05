#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ITEM_BUFFER 128
#define NAME_BUFFER 32
#define CAPACITIES_BUFFER 1024

#define ERROR_USAGE_MESSAGE "Usage: /tmp/knapsack capacity itemfile\r\n"
#define ERROR_ILLEGAL_CAPACITY "Illegal capacity: should be between 1 and 1024\r\n"

//This is what max value will return in order to give a value and an inventory
typedef struct Answer
{
	int value;
	int inventory[ITEM_BUFFER];
} Answer;

//This is what will be used to give information to 
typedef struct ItemDataBase
{
	char name[ITEM_BUFFER][NAME_BUFFER];
	int weight[ITEM_BUFFER];
	int value[ITEM_BUFFER];
	int itemCount;
} ItemDataBase;

Answer MaxValue(int capacity, ItemDataBase database, bool firstCall);

ItemDataBase* LoadItemDataBase(char* fileName);

void FreeItemDataBase(ItemDataBase* database);