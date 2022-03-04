#include "main.h"
//
//InventoryEntry* InitInventory(int cap, char* fileName)
//{
//	InventoryEntry* newInventory = malloc(sizeof(InventoryEntry) * cap + sizeof(InventoryEntry));
//
//	FILE* fileHandle = fopen(fileName, "r");
//	if (fileHandle == NULL) return NULL;
//
//	char chunk[1000];
//	char name[32];
//	int weight;
//	int value;
//
//	int i = 0;
//	while (fgets(chunk, sizeof(chunk), fileHandle) != NULL)
//	{
//		int sscanfResult = sscanf(chunk, "%s%d%d", name, &weight, &value);
//
//		if (sscanfResult != 3) continue;
//
//		InventoryEntry newEntry = malloc(sizeof(item));
//		newEntry->name = malloc(sizeof(char) * strlen(name) + sizeof(char));
//		strcpy(newEntry->name, name);
//		
//
//		newEntry->value = value;
//		newEntry->weight = weight;
//		newEntry->itemAmount = 0;
//
//		newInventory[i] = newEntry;
//		++i;
//	}
//
//	newInventory[i] = NULL;
//
//	fclose(fileHandle);
//
//	return newInventory;
//}
//
//
//void FreeInventory(InventoryEntry* inventory)
//{
//	for (int i = 0; inventory[i] != NULL; i++)
//	{
//		if (inventory[i]->name != NULL) free(inventory[i]->name);
//		if (inventory[i] != NULL) free(inventory[i]);
//	}
//	free(inventory);
//}