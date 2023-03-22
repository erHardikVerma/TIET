#include <bits/stdc++.h>
using namespace std;
 
void swap(int* a, int* b)
{
    int* t = a;
    a = b;
    b = t;
}
int partition(int a[], int low, int high)
{
    int pivot = a[low]; 
     int start=low;
     int end=high;
     while(start<end)
     {
	 
     while(a[start]<=pivot)
     {
     	start++;
	 }
	 while(a[end]<=pivot)
     {
     	end--;
     }
	 if(start<end)
	 {
	 	swap(a[start],a[end]);
	 }
}
swap(a[low],a[high]);

    return end;
}
 

void quickSort(int* arr, int low, int high)
{
    if (low < high) {

        int pivot = partition(arr, low, high);
 
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
 
