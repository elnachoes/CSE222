#include "main.h"

void main(int argc,char** argv)
{
    Node tree = NULL;

    // a b c d e f g h i

    tree = add(tree, "o", "asdf", "asdf");
    tree = add(tree, "h", "asdf", "asdf");
    tree = add(tree, "y", "asdf", "asdf");
    tree = add(tree, "a", "asdf", "asdf");
    tree = add(tree, "j", "asdf", "asdf");
    tree = add(tree, "z", "asdf", "asdf");
    tree = add(tree, "i", "asdf", "asdf");
    tree = add(tree, "l", "asdf", "asdf");
    tree = add(tree, "k", "asdf", "asdf");
    tree = add(tree, "x", "asdf", "asdf");
    tree = add(tree, "r", "asdf", "asdf");
    tree = add(tree, "w", "asdf", "asdf");

        
    //tree = LoadDatabase("database.txt");
    //tree = LoadDatabase("database.txt");
    //tree = LoadDatabase("database.txt");

    //tree = delete(tree, "c");
    printf("");
    tree = delete(tree, "o");
    printf("");

    treeFree(tree);
    //height(tree);
    //printf("\r\n");
    //LNR(tree);
    //printf("\r\n");
    //NLR(tree);
    //printf("\r\n");
    //LRN(tree);
    //printf("\r\n");



















    //Node tree = NULL;
    //if (argc >= 2)
    //{
    //    tree = LoadDatabase(argv[1]);
    //    if (tree == NULL)
    //    {
    //        return;
    //    }
    //}
    //else
    //{
    //    return;
    //}
    //
    //while (true)
    //{
    //    char UserInputBuffer[1000];
    //    char command[1000];
    //    char plate[257];
    //    char first[257];
    //    char last[257];

    //    // get input from the user
    //    printf("Enter a command or plate: ");
    //    char* fgetsResult = fgets(UserInputBuffer, 1000, stdin);

    //    // if they put in ctrl d exit
    //    if (fgetsResult == NULL)
    //    {
    //        printf("\r\nFreeing memory\r\n");
    //        break;
    //    }

    //    //int sscanfResult = sscanf(fgetsResult, "%s%s", command, plate);

    //    //printf("%d",sscanfResult);

    //    if (strcmp(fgetsResult, "*DUMP") == 0)
    //    {
    //        height(tree);
    //        printf("\r\n");
    //        LNR(tree);
    //        printf("\r\n");
    //        NLR(tree);
    //        printf("\r\n");
    //        LRN(tree);
    //        printf("\r\n");
    //    }
    //    else if (strcmp(command, "*DELETE") == 0)
    //    {
    //        if (sscanf(fgetsResult, "%s%s", command, plate) == 2)
    //        {
    //            if (search(tree,plate,first,last))
    //            {
    //                tree = delete(tree, plate);
    //                printf("SUCCESS\r\n");
    //            }
    //            else
    //            {
    //                printf("PLATE NOT FOUND\r\n");
    //            }
    //        }
    //        else
    //        {
    //            printf("PLATE NOT FOUND\r\n");
    //        }
    //    }
    //    else
    //    {
    //        
    //        if (search(tree, fgetsResult, first, last))
    //        {
    //            printf("First name: %s\r\n", first);
    //            printf("Last name: %s\r\n", last);
    //        }
    //        else
    //        {
    //            printf("PLATE NOT FOUND\r\n");
    //        }
    //        
    //    }
    //}

    //treeFree(tree);
}