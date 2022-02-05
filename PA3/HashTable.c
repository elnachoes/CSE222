#include "main.h"


int _hashSize;


hashEntry *hashInit(int hashsize)
{
    hashEntry* hashTable = malloc(sizeof(hashEntry[hashsize]));
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
    for (int i = 0; i < strlen(plate); i++)
    {
        hashResult += ( ( ( (i + 1) * (i + 1) ) * plate[i] ) % _hashSize - 1 );
    }
    return hashResult;
}



void hashAdd(hashEntry* hashTable, char* plate, char* first, char* last)
{
    listAdd(hashTable[ hash(plate) ],plate,first,last);
}



int hashFind(hashEntry* hashTable, char* plate, char* first, char* last)
{
    return listFind(hashTable[ hash(plate) ],plate, first, last);
}


void hashLoad(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        if (!hashTable[i])
        {
            printf("Entry %d: length=0\n",i);
        }
        else
        {
            printf("Entry %d: length=%d\n",i,listLen(hashTable[i]));
        }
    }
}


void hashDump(hashEntry* hashTable, int cellNum)
{
    listPrint(hashTable[cellNum]);
}


void hashFree(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        listFree(hashTable[i]);
    }
    free(hashTable);
}