#include "main.h"



void main()
{
    hashEntry* hashTable = hashInit(5);


    FILE* fp = fopen("database.txt","r");
    if (!fp)
    {
        printf("error : file does not exist");
    }

    char chunk[1000];
    char plate[257];
    char first[100];
    char last[100];

    while(fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        sscanf(chunk,"%s%s%s",plate,first,last);
        // printf("%s : hash = %d\n",plate, hash(plate));
        hashAdd(hashTable, plate, first, last);
    }

    // printf("%d",hash("asdf"));

    // hashAdd(hashTable,"asdf","dorf","dorf");
    // hashAdd(hashTable,"asdf","borf","dorf");

    // hashDump(hashTable,hash("asdf"));

    // strcpy(first,"GDB4FUN");

    // hashFind(hashTable, plate, first, last);



    // char* newplate = "GDB4FUN";
    // char* newfirst = malloc(sizeof(char));
    // char* newlast = malloc(sizeof(char));

    // int result = hashFind(hashTable, "PMF-430", newfirst, newlast);
    // printf("%d\n", result);

    // printf("%s",hashTable[1]->next->first);


    // hashLoad(hashTable);

    hashDump(hashTable,4);

    hashFree(hashTable);
}