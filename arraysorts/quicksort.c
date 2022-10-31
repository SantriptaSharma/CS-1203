#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int Partition(int *arr, int n)
{
    if (n == 1) return 0;
    int piv = arr[0];

    int x = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > piv) continue;
        if (i != ++x)
        {
            int tmp = arr[x];
            arr[x] = arr[i];
            arr[i] = tmp;
        }
    }

    arr[0] = arr[x];
    arr[x] = piv;
    return x;
}

void QuickSort(int *arr, int start, int stop)
{
    if (start >= stop)
    {
        return;
    }

    int piv = Partition(&arr[start], stop - start + 1) + start;
    QuickSort(arr, start, piv - 1);
    QuickSort(arr, piv + 1, stop);
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

    PrintList(arr, N);
    QuickSort(arr, 0, N-1);
    PrintList(arr, N);

    free(arr);
}