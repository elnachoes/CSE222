/// Author : Corbin Martin
/// Date : March 5th 2022
/// Program Name : KnapSack Solver (PA5 CSE222)
/// 
///	Summary : This is a program that reads in a list of items with a name value and weight
/// and uses a recursive function called MaxValue() which utilizes dynamic programming to
/// cache results from previous calls of MaxValue(). It will print the maximum value that
/// can be extracted from the set of items and which items would need to be picked and in 
/// what quantities. Each item in the database should be a "name value weight" and there
/// can only be a maximum of 128 items due to the spec of the assignment. The program is 
/// called with 2 arguments for the capacity (has to between 1 and 1024 due to the spec of
/// the assignment) and a .txt file that contains our database.

#include "main.h"

void main(int argc, char** argv)
{
	ItemDataBase* database = NULL;
	Answer answer;
	int capacity = 0;

	//process the cmd args and load in the item database
	if (argc == 3)
	{
		//load in the database from the file
		database = LoadItemDataBase(argv[2]);
		
		//if the database file isn't there and it returns null print the ussage error message and exit
		if (database == NULL)
		{
			printf(ERROR_USAGE_MESSAGE);
			return;
		}

		//load in the capacity
		int sscanfResult = sscanf(argv[1],"%d",&capacity);
		
		//if the sscanf didn't read in a integer print the ussage error message and exit
		if (sscanfResult == 0)
		{
			printf(ERROR_USAGE_MESSAGE);
			return;
		}
		//if they put in an illegal capacity (should be between 1 and 1024 by the assignment spec) print the illegal capacity error and exit
		else if (capacity > 1024 || capacity < 1)
		{
			printf(ERROR_ILLEGAL_CAPACITY);
			return;
		}
	}
	//if they didn't put in a correct number of arguments print the ussage error message and exit
	else
	{
		printf(ERROR_USAGE_MESSAGE);
		return;
	}

	//find the maxvalue given the database
	answer = MaxValue(capacity, *database, true);


	//print out the results of the database
	printf("\r\n");
	printf("Weight  Value   Name\r\n");
	printf("------  -----   ----\r\n");
	for (int i = 0; i < database->itemCount; i++)
	{
		printf("%d\t%d\t%s\r\n", database->weight[i], database->value[i], database->name[i]);
	}
	printf("--------------------\r\n");
	printf("Bag's capacity=%d\r\n", capacity);
	printf("Highest possible value=%d\r\n", answer.value);
	for (int i = 0; i < database->itemCount; i++)
	{
		if (answer.inventory[i] != 0)
		{
			printf("Item %d (%s): %d\r\n", i, database->name[i], answer.inventory[i]);
		}
	}

	//free the database
	FreeItemDataBase(database);
}