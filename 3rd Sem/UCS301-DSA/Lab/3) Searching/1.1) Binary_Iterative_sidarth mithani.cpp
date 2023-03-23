#include <iostream>
using namespace std;

//arr-array to be searched
//key is the element to be searched
//n is the size of the array

int binarySearchI(int arr[], int key, int n)
{
    int start = 0;
    int end = n - 1;
    while (true)
    {
        int mid = end - (end - start) / 2;
        if (start > end)
        {
            break;
        }
        else if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 45;
    int returned = binarySearchI(arr, key, 10);
    if (returned == -1)
    {
        cout << "Search Unsuccessful" << endl;
    }
    else
    {
        cout << "Search Successful at index: " << returned << endl;
    }
    return 0;
}
