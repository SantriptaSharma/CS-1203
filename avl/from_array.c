#include <stdio.h>
#include "avl.h"
#include "../utils.h"

int main()
{
    AVLNode *root = NULL;
    
    int N;

    printf("Enter number of elements: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        int el;

        printf("Enter element %d: ", i+1);
        scanf("%d", &el);
        Insert(&root, el);
    }
    
    printf("\n");

    PrintInOrder(root);

    FreeAVL(root);

    return 0;
}