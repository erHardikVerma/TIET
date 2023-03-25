//Time complexity=O(n^2)
//Space complexity=O(1)
#include<iostream>
using namespace std;
void selectionsort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int minindex=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[minindex]>arr[j])
            {
                minindex=j;
            }
        }
            int temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[100];
    int size;
    cout<<"Enter the size of the array\n";
    cin>>size;
    cout<<"Enter the elements\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"The array in selection sort order is given below\n";
    selectionsort(arr,size);
}
