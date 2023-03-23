#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int start, int end)
{
    // Considering the first element to be the pivot
    int pivot = arr[start];
    int count = 0;
    for (int i = (start + 1); i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivot_index = start + count;
    swap(arr[pivot_index], arr[start]);
    int i = start, j = end;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivot_index;
}

void quickSortIterative(int arr[], int start, int end)
{
    // Create an auxiliary stack
    int stack[end - start + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of start and end to stack
    stack[++top] = start;
    stack[++top] = end;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop end and start
        end = stack[top--];
        start = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, start, end);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > start)
        {
            stack[++top] = start;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < end)
        {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
}

// Printing the sorted array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortIterative(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}
