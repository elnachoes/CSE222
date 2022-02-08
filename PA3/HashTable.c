#include "main.h"


int _hashSize;


hashEntry* hashInit(int hashsize)
{
    hashEntry* hashTable = malloc(sizeof(hashEntry) * hashsize);
    _hashSize = hashsize;

    for (int i = 0; i < _hashSize; i++)
    {
        hashEntry sent = listInit();
        hashTable[i] = sent;
    }

    return hashTable;
}


int hash(char* plate)
{
    int hashResult = 0;
    for (int i = 0; i <= strlen(plate) - 1; i++)
    {
        hashResult += (((i + 1) * (i + 1)) * plate[i]);
    }
    return hashResult % _hashSize;
}


void hashAdd(hashEntry* hashTable, char* plate, char* first, char* last)
{
    listAdd(hashTable[hash(plate)], plate, first, last);
}


int hashFind(hashEntry* hashTable, char* plate, char* first, char* last)
{
    return listFind(hashTable[hash(plate)], plate, first, last);
}


void hashLoad(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        printf("Entry %d: length=%d\r\n", i, listLen(hashTable[i]));
    }
}


void hashDump(hashEntry* hashTable, int cellNum)
{
    if (cellNum < 0)
    {
        printf("ERROR: cell must be between 0 and 99\r\n");
    }
    else
    {
        printf("Contents of cell %d\r\n", cellNum);
        listPrint(hashTable[cellNum]);
        printf("----------------------------------\r\n");
    }
}

void hashDumpAll(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        hashDump(hashTable,i);
    }
}


void hashFree(hashEntry* hashTable)
{
    if(hashTable == NULL) return;

    for (int i = 0; i < _hashSize; i++)
    {
        listFree(hashTable[i]);
    }
    if(hashTable != NULL) free(hashTable);
}


FILE* LoadDatabase(hashEntry* hashTable, char* database)
{
    FILE* fp = fopen(database, "r");
    if (!fp)
    {
        printf("ERROR Cannot open %s\r\n", database);
        return NULL;
    }

    char chunk[1000];

    while (fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        char* tempPlate = malloc(sizeof(char) * 257);
        char* tempFirst = malloc(sizeof(char) * 100);
        char* tempLast = malloc(sizeof(char) * 100);

        sscanf(chunk, "%s%s%s", tempPlate, tempFirst, tempLast);

        hashAdd(hashTable, tempPlate, tempFirst, tempLast);
    }
    return fp;
}


void CloseDatabase(FILE* fileHandle)
{
    if (fileHandle != NULL) fclose(fileHandle);
}