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

    PrintInOrder(root);

    FreeBST(root);

    return 0;
}