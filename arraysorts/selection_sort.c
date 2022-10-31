#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int FindMinIndex(int *arr, int start, int n)
{
    int min = 0;

    for(int i = 1; i < n; i++)
    {
        if (arr[start + i] >= arr[start + min]) continue;

        min = i;
    }
    
    return start + min;
}

void SelectionSort(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int o = FindMinIndex(arr, i, n - i);
        
        if (i == o) continue;

        int h = arr[i];
        arr[i] = arr[o];
        arr[o] = h;
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

    PrintList(arr, N);
    SelectionSort(arr, N);
    PrintList(arr, N);

    free(arr);
}