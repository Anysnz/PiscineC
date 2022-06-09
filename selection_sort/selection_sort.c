#include <stdio.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int mini = start;
    for (int k = start + 1; k < size; k++)
    {
        if (arr[mini] > arr[k])
        {
            mini = k;
        }
    }
    return arr[mini];
}
void selection_sort(int arr[], unsigned size)
{
    int tmp;
    arr[] = (const int)arr[];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j > i && arr[j] < arr[i])
                arr[i] = array_min(arr[i], 0, size);
            else
                tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
}
