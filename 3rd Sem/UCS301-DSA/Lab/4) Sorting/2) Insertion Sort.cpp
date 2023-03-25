//Time Complexity=O(n^2)
//Best case=O(n)
//Space complexity=O(1)
#include<iostream>
using namespace std;
void insertionsort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {

        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[100];
    int size;
    cout<<"Enter the size of the array\n";
    cin>>size;
    cout<<"Enter the elements\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"The insertion sort ordered array is given below\n";
    insertionsort(arr,size);
}
