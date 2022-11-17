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
        PrintInOrder(root);
    }
    
    printf("\n");
    PrintInOrder(root);
    printf("\n");

    printf("Number of deletions: \n");
    int D;
    scanf("%d", &D);
    for (int i = 0; i < D && i < N; i++)
    {
        printf("Value to remove: \n");
        int t;
        scanf("%d", &t);

        AVLNode *target = Find(root, t);
        if (!target) 
        {
            printf("Delete failed, target not found\n");
            continue;
        }
        
        root = Delete(target);
        PrintInOrder(root);
    }

    FreeAVL(root);

    return 0;
}