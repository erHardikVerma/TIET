#include <iostream>
using namespace std;


int partition(int arr[], int start, int end)
{ 
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
void quickSort(int arr[], int start, int end)
{
    // Base Case
    if (start >= end)
        return;
    // Do partition
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, (p - 1));
    // Sorting the right part
    quickSort(arr, (p + 1), end);
}
int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;
    quickSort(arr, 0, (n - 1));
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}
