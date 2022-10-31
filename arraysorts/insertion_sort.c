#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

void InsertionSort(int *arr, int n)
{
    for (int border = 0; border < n - 1; border++)
    {
        int value = arr[border + 1];

        for (int i = border; i >= 0 && value < arr[i]; i--)
        {
            int h = arr[i];
            arr[i] = value;
            arr[i + 1] = h;
        }
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
    InsertionSort(arr, N);
    PrintList(arr, N);

    free(arr);
}