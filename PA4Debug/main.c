#include "main.h"

void main()
{
    Node tree = NULL;


    // a b c d e f g h i
    tree = add(tree,"c","asdf","asdf");
    tree = add(tree,"b","asdf","asdf");
    tree = add(tree,"d","asdf","asdf");
    tree = add(tree,"e","asdf","asdf");
    tree = add(tree,"a","asdf","asdf");
    tree = add(tree,"f","asdf","asdf");
    tree = add(tree,"i","asdf","asdf");
    tree = add(tree,"h","asdf","asdf");
    tree = add(tree,"g","asdf","asdf");


    LNR_debug(tree);
    printf("\n\r");
    tree = delete(tree, "c");
    tree = delete(tree, "e");
    tree = delete(tree, "i");
    printf("\n\r");
    LNR_debug(tree);


    ///debug notes
    ///ROOT CANNOT BE DELETED
    ///REPARENT DOESN'T WORK
    /// 
    /// 
    /// DEBUG CHECKLIST
    /// c no work
    /// b work
    /// d work
    /// 



    //printf("%d",height(tree));

    treeFree(tree);
}