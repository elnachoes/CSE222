// author : corbin martin
// date : 2/8/2022
// class : CSE222
// summary : this is a program that loads in a database of license plate names, first names, and last names
// and stores them INSIDE of a hash table with linked lists at each index to use chaingin as a means of collision management.
// the main program can allow you to index and read items stored in the hash table as well as monitor the load on each of the
// indexes in the hash table.

#include "main.h"

//this cleans up the dynamically allocated things used in the main cmd
//frees the hash table and the file handle tot he database
void CleanupMain(hashEntry* hashTable, FILE* databaseFileHandle)
{
    CloseDatabase(databaseFileHandle);
    hashFree(hashTable);
}

void main(int argc, char** argv)
{
    //default hash size is 100 elements
    int hashSize = 100;

    hashEntry* hashTable = NULL;
    FILE* databaseFileHandle =  NULL;

    // PROCESSING CMD ARGS
    //if there are only two args set the hash table to 100 elements and load the database
    if (argc == 2)
    {
        hashTable = hashInit(100);
        databaseFileHandle = LoadDatabase(hashTable, argv[1]);

        //if the file doesn't exist exit
        if (!databaseFileHandle)
        {
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }
    }
    //if there are only 3 args set the hash table with the hash size and load the database
    else if (argc == 3)
    {
        int result = sscanf(argv[2],"%d",&hashSize);

        //if user put in too small a hash size exit
        if (hashSize < 1)
        {
            printf("ERROR: Hashsize should be at least 1\r\n");
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }

        if (result == 1)
        {
            hashTable = hashInit(hashSize);
            databaseFileHandle = LoadDatabase(hashTable, argv[1]);
        }

        //if they dont give a correct argument for hash size exit
        else
        {
            printf("Usage: ./plate database [hashsize]\r\n");
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }

        //if the file doesn't exist exit
        if (!databaseFileHandle)
        {
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }
    }
    // if they didn't put in ANY cmd args
    else
    {
        printf("Usage: ./plate database [hashsize]\r\n");
        CleanupMain(hashTable, databaseFileHandle);
        return;
    }

    // MAIN CMD LOOP
    while (true)
    {
        char UserInputBuffer[1000];
        char command[1000];
        int commandArg;

        // get input from the user
        printf("Enter a command or plate: ");
        char* fgetsResult = fgets(UserInputBuffer,1000,stdin);

        // if they put in ctrl d exit
        if(fgetsResult == NULL)
        {
            printf("\r\nFreeing memory\r\n");
            break;
        }

        // parse the input
        int result = sscanf(UserInputBuffer,"%s%d",command, &commandArg);

        //if they put in load load the hash table
        if (!strcmp(command,"*LOAD"))
        {
            hashLoad(hashTable);
        }

        //if they put in dump dump everything in the hash table
        else if (!strcmp(command,"*DUMP") && result == 1)
        {
            hashDumpAll(hashTable);
        }

        //if they put in dump and a number dump that cell in the hash table
        else if (!strcmp(command,"*DUMP") && result == 2)
        {
            hashDump(hashTable,commandArg);
        }

        //search the hash list to see if they are looking up a plate stored in the hash table
        else
        {
            char firstname[500];
            char lastname[500];
            int hashFindResult = hashFind(hashTable,command,firstname,lastname);
            if (hashFindResult)
            {
                printf("First name: %s\r\n", firstname);
                printf("Last name: %s\r\n", lastname);
            }
            else
            {
                printf("Plate not found\r\n");
            }
        }
    }

    //clean up the dynamically allocated variables
    CleanupMain(hashTable, databaseFileHandle);
}