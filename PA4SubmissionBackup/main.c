#include "main.h"

void main(int argc,char** argv)
{
    // initialize the tree to null to start out with
    Node tree = NULL;
    
    // handle cmc args
    if (argc == 2)
    {
        // load database will initialize the tree with the data in the database and return an initialized tree
        tree = LoadDatabase(argv[1]);
        if (tree == NULL)
        {
            // if the database doesn't exist print this error and get out
            printf("ERROR Cannot open %s\r\n", argv[1]);
            return;
        }
    }
    else
    {
        // if they didn't put in a seccond cmd arg let them know and hop out
        printf("Usage: ./plate4 databasefile");
        return;
    }
    
    // main program loop
    while (true)
    {
        // strings for data processing
        char UserInputBuffer[STRING_BUFFER];
        char arg1[STRING_BUFFER];
        char arg2[STRING_BUFFER];
        char first[STRING_BUFFER];
        char last[STRING_BUFFER];

        // get input from the user
        printf("Enter a command or plate: ");
        char* fgetsResult = fgets(UserInputBuffer, STRING_BUFFER, stdin);

        // if they put in ctrl d exit
        if (fgetsResult == NULL)
        {
            printf("\r\nFreeing memory\r\n");
            break;
        }

        // scan in arguments from the user
        int sscanfResult = sscanf(fgetsResult, "%s%s", arg1, arg2);

        // if they put in *DUMP print the height, if it was balanced, LNR traversal, NLR traversal, and LRN traversal
        if (strcmp(arg1, "*DUMP") == 0)
        {
            printf("\r\n");
            printf("TREE HEIGHT: %d\r\n", height(tree));

            (balanced(tree)) ? printf("BALANCED: YES\r\n\r\n") : printf("BALANCED: NO\r\n\r\n");

            printf("LNR TRAVERSAL:\r\n");
            LNR(tree);
            printf("\r\n");
            printf("NLR TRAVERSAL:\r\n");
            NLR(tree);
            printf("\r\n");
            printf("LRN TRAVERSAL:\r\n");
            LRN(tree);
            printf("\r\n");
        }
        // if they put in *DELETE and they gave a argument for what to delete, delete a node
        else if (strcmp(arg1, "*DELETE") == 0 && sscanfResult == 2)
        {
            //if the search returns a 1 delete the node in the tree 
            if (search(tree,arg2,first,last))
            {
                tree = delete(tree, arg2);
                printf("SUCCESS\r\n");
            }
            //if it couldn't find the node let the user knmow
            else
            {
                printf("PLATE NOT FOUND\r\n");
            }
        }
        else
        {
            //if the search returns a 1 print the first and last that comes back from search
            if (search(tree, arg1, first, last))
            {
                printf("First name: %s\r\n", first);
                printf("Last name: %s\r\n", last);
            }
            //if it couldn't find the node let the user knmow
            else
            {
                printf("PLATE NOT FOUND\r\n");
            }
        }
    }

    //free the tree 
    treeFree(tree);
}