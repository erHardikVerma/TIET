#include <iostream>
using namespace std;

//Following function is used to merge the 2 sorted arrays
void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;//To store the length of first array
    int len2 = end - mid;//To store the length of the second array

    //Dynamic initialization of an empty 1 d array
    int *first = new int[len1];
    int *second = new int[len1];

    // Copy Values
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    k = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
            arr[k++] = second[index2++];
    }
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[] = {1, 2, 2, 6, 6, 100, 4, 9, 5};
    int n = 9;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
