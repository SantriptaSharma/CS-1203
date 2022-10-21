#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

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

    if (head->next != NULL) FreeList(head->next);
    free(head);
}

void ReverseList(Node **head)
{
    Node *cur = (*head)->next, *prev = *head;
    (*head)->next = NULL;

    while (cur)
    {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;
}

void ChunkReverseList(Node **head, int chunkSize)
{
    if (chunkSize <= 0) return;
    if (chunkSize == 1) return ReverseList(head);


    Node *cur = *head, *prev = NULL;
    Node *chunkStart = NULL, *lastChunkEnd = NULL;

    int index = 0;

    while (cur)
    {
        Node *next = cur->next;

        int indexInChunk = index % chunkSize;

        if (indexInChunk == 0)
        {
            lastChunkEnd = chunkStart;
            chunkStart = cur;
            prev = NULL;
        }
        else if (indexInChunk == chunkSize - 1 || next == NULL)
        {
            if (index / chunkSize == 0) *head = cur;
            if (lastChunkEnd) lastChunkEnd->next = cur;
            chunkStart->next = next;
        }

        cur->next = prev;
        prev = cur;
        cur = next;
        index += 1;
    }
}

static Node* FindPrevOfSmallest(Node *head)
{
    int minimum = head->value;
    Node *minimumPrev = NULL;

    for (; head; head = head->next)
    {
        if (head->next && head->next->value < minimum)
        {
            minimum = head->next->value;
            minimumPrev = head;
        }
    }

    return minimumPrev;
}

void SelectionSort(Node **head)
{
    Node *sortHead = *head, *prev = NULL;

    while (sortHead)
    {
        Node *prevOfMinimum = FindPrevOfSmallest(sortHead);

        if (prevOfMinimum == NULL) 
        {
            prev = sortHead;
            sortHead = sortHead->next;
            continue;
        }

        if (prev == NULL)
        {
            *head = prevOfMinimum->next;
            prevOfMinimum->next = prevOfMinimum->next->next;
            (*head)->next = sortHead;

            prev = *head;
        }
        else
        {
            prev->next = prevOfMinimum->next;
            prevOfMinimum->next = prevOfMinimum->next->next;
            prev->next->next = sortHead;

            prev = prev->next;
        }
    }
}