#include "main.h"

#define ITEM_BUFFER 128
#define NAME_BUFFER 32
#define CAPACITIES_BUFFER 1024

//This is what max value will return in order to give a value and an inventory
typedef struct Answer
{
	int value;
	int inventory[ITEM_BUFFER];
} Answer;


char name[ITEM_BUFFER][NAME_BUFFER];
int weight[ITEM_BUFFER];
int value[ITEM_BUFFER];
int inventory[ITEM_BUFFER] = { 0 };
int capacitiesCache[ITEM_BUFFER][CAPACITIES_BUFFER] = { 0 };
int recurranceCount = 0;

int itemCount;

Answer maxValueCache[ITEM_BUFFER][CAPACITIES_BUFFER];

Answer MaxValue(int capacity)
{
	//bestAnswer always defaults to zero in the event that you cant fit any items into the new cap
	Answer bestAnswer = { 0, {0} };

	//for each item in the item list find the best values for the amount of items to their values
	for (int i = 0; i < itemCount; i++)
	{
		//if the weight is greater than the capacity dont try to calculate a best value because there is none
		if (weight[i] <= capacity)
		{
			int newValue;
			Answer newAnswer;

			//if the MaxValue was already calculated for a certain value retrieve it from the cache
			if (maxValueCache[i][capacity - weight[i]].value != -1)
			{
				newAnswer = maxValueCache[i][capacity - weight[i]];
				newValue = value[i] + newAnswer.value;
			}
			//if the MaxValue was NOT already calculated go calculate it
			else
			{
				newAnswer = MaxValue(capacity - weight[i]);
				maxValueCache[i][capacity - weight[i]] = newAnswer;
				newValue = value[i] + newAnswer.value;
			}

			if (newValue > bestAnswer.value)
			{
				bestAnswer = newAnswer;
				bestAnswer.value = newValue;
				++bestAnswer.inventory[i];
			}
		}
	}

	//for tracking how many times the recurrence has happened
	++recurranceCount;
	return bestAnswer;
}


///THIS IS THE OLD VERSION THAT RETURNS AN INT
///I will leave it in for reference
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

void main(int argc, char** argv)
{
	memset(capacitiesCache, -1, sizeof(capacitiesCache));

	for (int i = 0; i < ITEM_BUFFER; i++)
		for (int j = 0; j < CAPACITIES_BUFFER; j++)
			maxValueCache[i][j].value = -1;




	//memset(maxValueCache)

	int cap = 22;

	strcpy(name[0], "qwer");
	weight[0] = 5;
	value[0] = 8;

	strcpy(name[1], "asdf");
	weight[1] = 1;
	value[1] = 1;

	//strcpy(name[2], "zxcv");
	//weight[2] = 2;
	//value[2] = 99;


	itemCount = 2;

	//int test = MaxValue(cap);
	
	Answer answer = MaxValue(cap);
	
	printf("");
}