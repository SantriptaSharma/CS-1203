#include <stdio.h>
#include "linkedlist.h"

int main()
{
    int N;

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

    SelectionSort(&head);
    printf("Sorted list (hopefully): ");
    PrintList(head);

    FreeList(head);
}