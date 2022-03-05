#include "main.h"

//this is a function that returns a struct containing a maximum value possible from a set of items in a knapsack
//capacity is the current capacity of the knapsack
//database is the current list of items with their names values and weights stored in it
//firstCall MUST BE TRUE THE FIRST TIME THE FUNCTION IS CALLED TO PROPERLY CACHE FUNCTION RESULTS
Answer MaxValue(int capacity, ItemDataBase database, bool firstCall)
{
	//maxValueCache is better if it is static because it is only used by MaxValue() and it needs to be preserved between recursive calls
	static Answer maxValueCache[ITEM_BUFFER][CAPACITIES_BUFFER];

	//if the first call flag is triggered initialize maxValueCache to have a -1 in each value field and set the firstCall flag to false
	if (firstCall)
	{
		for (int i = 0; i < ITEM_BUFFER; i++)
			for (int j = 0; j < CAPACITIES_BUFFER; j++)
				maxValueCache[i][j].value = -1;
		firstCall = false;
	}

	//bestAnswer always defaults to zero in the event that you cant fit any items into the new cap
	Answer bestAnswer = { 0, {0} };

	//for each item in the item list find the best values for the amount of items to their values
	for (int i = 0; i < database.itemCount; i++)
	{
		//if the weight is greater than the capacity dont try to calculate a best value because there is none
		if (database.weight[i] <= capacity)
		{
			int newValue;
			Answer newAnswer;

			//if the MaxValue was already calculated for a certain value retrieve it from the cache
			if (maxValueCache[i][capacity - database.weight[i]].value != -1)
			{
				newAnswer = maxValueCache[i][capacity - database.weight[i]];
				newValue = database.value[i] + newAnswer.value;
			}
			//if the MaxValue was NOT already calculated go calculate it
			else
			{
				newAnswer = MaxValue(capacity - database.weight[i], database, firstCall);
				maxValueCache[i][capacity - database.weight[i]] = newAnswer;
				newValue = database.value[i] + newAnswer.value;
			}

			if (newValue > bestAnswer.value)
			{
				bestAnswer = newAnswer;
				bestAnswer.value = newValue;
				++bestAnswer.inventory[i];
			}
		}
	}
	return bestAnswer;
}

//this creates a database from a file that lays out an item for each line 
//each line will store information as : "name value weight"
ItemDataBase* LoadItemDataBase(char* fileName)
{
	FILE* fileHandle = fopen(fileName, "r");

	ItemDataBase* newDataBase = malloc(sizeof(ItemDataBase));
	if (fileHandle == NULL) return NULL;
	
	newDataBase->itemCount = 0;
	
	char chunk[1000];
	char name[NAME_BUFFER];
	int weight;
	int value;
	int i = 0;
	while (fgets(chunk, sizeof(chunk), fileHandle) != NULL)
	{
		int sscanfResult = sscanf(chunk, "%s%d%d", name, &value, &weight);

		if (sscanfResult == 3)
		{
			newDataBase->value[i] = value;
			newDataBase->weight[i] = weight;
			strcpy(newDataBase->name[i], name);

			++newDataBase->itemCount;
			++i;
		}
	}

	fclose(fileHandle);
	return newDataBase;
}

//this just frees a loaded database that loaded from a file
void FreeItemDataBase(ItemDataBase* database) { if(database != NULL) free(database); }


///THIS IS THE OLD VERSION OF MAXVALUE THAT RETURNS AN INT
///I will leave it in as a comment for future reference
//int MaxValue(int cap)
//{
//	int best = 0;
//	for (int i = 0; i < itemCount; i++)
//	{
//		if (weight[i] <= cap)
//		{
//			int newValue;
//			if (capacitiesCache[i][cap - weight[i]] != -1)
//			{
//				newValue = capacitiesCache[i][cap - weight[i]];
//			}
//			else
//			{
//				newValue = value[i] + MaxValue(cap - weight[i]);
//				capacitiesCache[i][cap - weight[i]] = newValue;
//			}
//			
//			if (newValue > best)
//			{
//				best = newValue;
//			}
//
//			inventory[i] = cap / newValue;
//		}
//	}
//
//	//for tracking how many times the recurrence has happened
//	++recurranceCount;
//	return best;
//}