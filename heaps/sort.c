#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

void Heapify(int *arr, int i, int n)
{
    int maximum = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[maximum])
    {
        maximum = l;
    }

    if (r < n && arr[r] > arr[maximum])
    {
        maximum = r;
    }

    if (maximum != i)
    {
        ArraySwap(arr, i, maximum);

        Heapify(arr, maximum, n);
    }
}

void ExtractMaxToEnd(int *heap, int N)
{
    if (N == 0) return;

    ArraySwap(heap, 0, N-1);
    Heapify(heap, 0, N-1);
}

int main()
{
    int N;

    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nCreated array: ");
    PrintList(arr, N);

    for (int i = N/2; i >= 0; i--)
    {
        Heapify(arr, i, N);
    }

    printf("Max-Heapified: ");
    PrintList(arr, N);

    for (int i = N; i > 1; i--)
    {
        ExtractMaxToEnd(arr, i);
    }

    printf("Heap sorted: ");
    PrintList(arr, N);

    free(arr);
}