#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

void Heapify(int *arr, int i, int n)
{
    int minimum = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] < arr[minimum])
    {
        minimum = l;
    }

    if (r < n && arr[r] < arr[minimum])
    {
        minimum = r;
    }

    if (minimum != i)
    {
        ArraySwap(arr, i, minimum);

        Heapify(arr, minimum, n);
    }
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

    printf("Min-Heapified: ");
    PrintList(arr, N);

    free(arr);
}