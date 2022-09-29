#include <stdio.h>
#include <stdlib.h>

typedef struct _NodeCanonical
{
    int value;
    struct _NodeCanonical *next;
} Node;

void Insert(Node **head, int value)
{
    Node *new = malloc(sizeof(*new));
    new->next = NULL;
    new->value = value;

    if (*head == NULL)
    {
        *head = new;
        return;
    }

    Node *it = *head;
    while (it->next != NULL)
    {
        it = it->next;
    }

    it->next = new;
}

void PrintList(Node *head)
{
    int i = 0;

    printf("[");
    while (head != NULL)
    {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("]\n");
}

void FreeList(Node *head)
{
    if (head == NULL) return;

    if (head->next == NULL)
    {
        free(head);
        return;
    }

    FreeList(head->next);
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    Insert(&head, 5);
    Insert(&head, 12);
    Insert(&head, 32);
    Insert(&head, 15);
    Insert(&head, 25);
    PrintList(head);
    FreeList(head);
}