#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
	char* name;
	int value;
	int weight;
} item;

//typedef struct answer
//{
//	int answer;
//	item inventory[129];
//};




typedef item* InventoryEntry;

InventoryEntry* InitInventory(int cap, char* fileName);

void FreeInventory(InventoryEntry* inventory);

int MaximizeInventory(int cap);