#include "main.h"


int hash(char* plate, int hashTableSize)
{
    int hashResult = 0;
    for (int i = 0; i < strlen(plate); i++)
    {
        hashResult += ( ( ( (i + 1) * (i + 1) ) * plate[i] ) % hashTableSize );
    }
    return hashResult;
}



void hashAdd(hashEntry* hashTable, char* plate, char* first, char* last)
{
}


int hashFind(hashEntry* hashTable, char* plate, char* first, char* last)
{
    return 1; //just so the compiler doesn't flip me off
}


void hashLoad(hashEntry* hashTable)
{

}


void hashDump(hashEntry* hashTable, int cellNum)
{

}


void hashFree(hashEntry* hashTable)
{

}