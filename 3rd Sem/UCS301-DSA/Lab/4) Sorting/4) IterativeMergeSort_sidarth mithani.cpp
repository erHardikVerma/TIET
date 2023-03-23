#include <iostream>
using namespace std;

// Function to merge the 2 created sub arrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    // size of the left array
    int n1 = mid - left + 1;
    // size of the right array
    int n2 = right - mid;

    int L[n1], R[n2];

    // Filling the elements of the right and left array
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // merging the left and right array
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of the left subarray
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copying the remaining elements of the right subarray
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// function to find minimum of two integers
int min(int x, int y) { return (x < y) ? x : y; }

// Iterative merge sort function
void mergeSort(int arr[], int n)
{
    int curr_size; // Stores the size of the subarrays to be merged together

    int left_start; // For picking starting index of left subarray

    // Merge subarrays in bottom up manner. First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            // endpoint of the left subarray
            int mid = min(left_start + curr_size - 1, n - 1);

            // mid+1 is starting point of right

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
        }
    }
}

// Function to print the sorted array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << A[i];
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is \n ";
    printArray(arr, n);
    mergeSort(arr, n);
    cout << "\nSorted array is \n ";
    printArray(arr, n);
    return 0;
}
