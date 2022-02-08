#include "main.h"

void CleanupMain(hashEntry* hashTable, FILE* databaseFileHandle)
{
    CloseDatabase(databaseFileHandle);
    hashFree(hashTable);
}

void main(int argc, char** argv)
{
    int hashSize = 100;

    hashEntry* hashTable = NULL;
    FILE* databaseFileHandle =  NULL;

    // PROCESSING CMD ARGS
    if (argc == 2)
    {
        hashTable = hashInit(100);
        databaseFileHandle = LoadDatabase(hashTable, argv[1]);

        if (!databaseFileHandle)
        {
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }
    }
    else if (argc == 3)
    {
        int result = sscanf(argv[2],"%d",&hashSize);

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
        else
        {
            printf("Usage: ./plate database [hashsize]\r\n");
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }

        if (!databaseFileHandle)
        {
            CleanupMain(hashTable, databaseFileHandle);
            return;
        }
    }
    else
    {
        printf("Usage: ./plate database [hashsize]\r\n");
        CleanupMain(hashTable, databaseFileHandle);
        return;
    }

    // printf("Enter command or plate: ");

    // MAIN CMD LOOP
    while (true)
    {
        char UserInputBuffer[1000];
        char command[1000];
        int commandArg;

        printf("Enter a command or plate: ");
        char* fgetsResult = fgets(UserInputBuffer,1000,stdin);

        if(fgetsResult == NULL)
        {
            printf("\r\nFreeing memory\r\n");
            break;
        }

        int result = sscanf(UserInputBuffer,"%s%d",command, &commandArg);

        if (!strcmp(command,"*LOAD"))
        {
            hashLoad(hashTable);
        }

        else if (!strcmp(command,"*DUMP") && result == 1)
        {
            hashDumpAll(hashTable);
        }

        else if (!strcmp(command,"*DUMP") && result == 2)
        {
            hashDump(hashTable,commandArg);
        }
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
    CleanupMain(hashTable, databaseFileHandle);
}