#include <stdio.h>
#include "bst.h"
#include "../utils.h"

int main()
{
    BSTNode *root = NULL;
    
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

    printf("Created BST: ");
    PrintInOrder(root);

    int val;
    printf("Enter the value of element to be deleted: ");
    scanf("%d", &val);

    BSTNode *target = Find(root, val);

    if (target == NULL)
    {
        printf("Target not found\n");
    } 
    else
    {
        root = Delete(target);
    }

    printf("BST: ");
    PrintInOrder(root);

    FreeBST(root);

    return 0;
}