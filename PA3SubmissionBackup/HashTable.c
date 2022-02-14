#include "main.h"

//size of the hash table
int _hashSize;

//hash table constructor
//creates a sentinal node at each index of the list
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

//creates a index for an item to be stored in the hash table based on the input string
int hash(char* plate)
{
    int hashResult = 0;
    for (int i = 0; i <= strlen(plate) - 1; i++)
    {
        hashResult += (((i + 1) * (i + 1)) * plate[i]);
    }
    return hashResult % _hashSize;
}

//adds a entry to the hash table at the index of the hash return value
void hashAdd(hashEntry* hashTable, char* plate, char* first, char* last)
{
    //hashtable indexed with hash(plate) should return the sentinal node of the linked list storing the value of the plate
    listAdd(hashTable[hash(plate)], plate, first, last);
}

//finds an element in the hash table by plate and if it is found it puts the name of the item in first and last
//returns a 1 if found and a 0 if not
int hashFind(hashEntry* hashTable, char* plate, char* first, char* last)
{
    return listFind(hashTable[hash(plate)], plate, first, last);
}

//displays the amount of items in each of the linked lists inside the hash table
void hashLoad(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        printf("Entry %d: length=%d\r\n", i, listLen(hashTable[i]));
    }
}

//prints the contents of a specific cell in the hash table
void hashDump(hashEntry* hashTable, int cellNum)
{
    if (cellNum < 0)
    {
        printf("ERROR: cell must be between 0 and %d\r\n",_hashSize - 1);
    }
    else
    {
        printf("Contents of cell %d\r\n", cellNum);
        listPrint(hashTable[cellNum]);
        printf("----------------------------------\r\n");
    }
}

//prints the contents of every cell in the hash table
void hashDumpAll(hashEntry* hashTable)
{
    for (int i = 0; i < _hashSize; i++)
    {
        hashDump(hashTable,i);
    }
}

//frees every linked list stored at every index in the hash table
void hashFree(hashEntry* hashTable)
{
    if(hashTable == NULL) return;

    for (int i = 0; i < _hashSize; i++)
    {
        listFree(hashTable[i]);
    }
    if(hashTable != NULL) free(hashTable);
}

//this loads in a database file and stores its contents INSIDE the hash table and returns a file handle
FILE* LoadDatabase(hashEntry* hashTable, char* database)
{
    FILE* fp = fopen(database, "r");
    if (!fp)
    {
        printf("ERROR Cannot open %s\r\n", database);
        return NULL;
    }

    char chunk[1000];
    char plate[257];
    char first[257];
    char last[257];

    while (fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        sscanf(chunk, "%s%s%s", plate, first, last);
        hashAdd(hashTable, plate, first, last);
    }
    return fp;
}

//closes the file handle to the database
void CloseDatabase(FILE* fileHandle)
{
    if (fileHandle != NULL) fclose(fileHandle);
}