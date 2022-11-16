#include <stdio.h>
#include "avl.h"
#include "../utils.h"

int main()
{
    AVLNode *root = NULL;
    
    Insert(&root, 15);
    Insert(&root, 3);
    Insert(&root, 6);
    Insert(&root, 1);
    Insert(&root, 0);
    Insert(&root, 43);
    Insert(&root, 7);
    Insert(&root, 3);
    Insert(&root, 8);
    PrintInOrder(root);

    FreeAVL(root);

    return 0;
}