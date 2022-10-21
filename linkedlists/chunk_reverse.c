#include <stdio.h>
#include "linkedlist.h"

int main()
{
    int N, K;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    Node *head = NULL;
    
    for (int i = 0; i < N; i++)
    {
        int el;

        printf("Enter element %d: ", i+1);
        scanf("%d", &el);
        Insert(&head, el);
    }

    printf("Created linked list: ");
    PrintList(head);

    printf("Enter chunk size: ");
    scanf("%d", &K);

    ChunkReverseList(&head, K);
    printf("Chunk Reversed with size %d: ", K);
    PrintList(head);
    FreeList(head);
}