//Time complexity=O(n^2)
//Space complexity=O(1)
#include<iostream>
using namespace std;
int partition(int arr[],int s,int e)
{
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(pivot>=arr[i])
        {
            count++;
        }
    }
    int pivotindex=s+count;
    int temp=arr[pivotindex];
    arr[pivotindex]=arr[s];
    arr[s]=temp;
    int i=s;
    int j=e;
    while(i<pivotindex&&j>pivotindex)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
    }
    if(i<pivotindex&&j>pivotindex)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main()
{
    int arr[20];
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s=0;
    int e=n-1;
    quicksort(arr,s,e);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
