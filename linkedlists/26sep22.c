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
    printf("[");
    while (head != NULL)
    {
        printf("%d", head->value);
        if (head->next != NULL) printf(", ");
        head = head->next;
    }
    printf("]\n");
}

void PrintHalfList(Node *head)
{
    Node *tort, *hare;

    tort = hare = head;

    printf("[");
    while (hare)
    {
        printf("%d", tort->value);
        tort = tort->next;

        hare = hare->next;
        if (hare && hare->next) printf(", ");
        if (hare) hare = hare->next;
    }
    printf("]\n");
}

int IsListLooping(Node *head)
{
    Node *t, *h;
    t = h = head;

    while (h)
    {
        h = h->next;
        if (t == h) return 1;
        if (!h) break;
        h = h->next;
        if (t == h) return 1;
        t = t->next;
    }

    return 0;
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
    free(head);
}

int main(int argc, char **argv)
{
    Node *head = NULL;
    Insert(&head, 5);
    Insert(&head, 12);
    Insert(&head, 32);
    PrintHalfList(head);
    Insert(&head, 15);
    Insert(&head, 25);
    PrintList(head);
    Insert(&head, 32);
    PrintList(head);
    PrintHalfList(head);

    Node *temp = head->next->next->next;
    printf("%d\n", IsListLooping(head));
    head->next->next->next = head->next;
    printf("%d\n", IsListLooping(head));
    head->next->next->next = temp;
    printf("%d\n", IsListLooping(head));

    FreeList(head);
}