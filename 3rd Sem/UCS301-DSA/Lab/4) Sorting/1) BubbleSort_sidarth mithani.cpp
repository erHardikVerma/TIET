#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 5, 6, 9};
    int n = 5;
    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] >= arr[j+1])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    // Printing the sorted array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
