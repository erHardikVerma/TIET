#include <iostream>
using namespace std;

// arr-array to be searched
// key is the element to be searched
//start-starting index
//end-last index of the array
// n is the size of the array
int binarySearchR(int arr[], int start, int end, int key)
{
    int mid = end - (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    else if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        return binarySearchR(arr, (mid + 1), end, key);
    }
    else if (arr[mid] > key)
    {
        return binarySearchR(arr, start, (mid - 1), key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 45;
    int returned = binarySearchR(arr, 0, 9, 11);
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
