#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {64, 25, 12, 22, 11}; 
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        int sm = arr[i];
        int sm_index = i;
        // Loop to find the smallest element
        for (int j = (i + 1); j < n; j++)
        {
            if (arr[j] <= sm)
            {
                sm = arr[j];
                sm_index = j;
            }
        }
        // Swapping the element
        int temp = arr[i];
        arr[i] = arr[sm_index];
        arr[sm_index] = temp;
    }
    // Display
    cout << "The sorted array is as follows" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
