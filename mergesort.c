#include <stdio.h>

void merge(int arr[], int st, int mid, int end)
{
    int temp[100];

    int i = st;
    int j = mid + 1;
    int k = 0;

    // Compare both sorted halves
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Left half still has elements
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Right half still has elements
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp back to arr
    for (i = st, k = 0; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        // Divide left half
        mergeSort(arr, st, mid);

        // Divide right half
        mergeSort(arr, mid + 1, end);

        // Merge sorted halves
        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {53, 20, 15, 6, 9, 8, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}