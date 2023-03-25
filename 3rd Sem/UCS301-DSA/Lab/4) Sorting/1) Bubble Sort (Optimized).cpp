//Time complexity=O(n^2)
//Space complexity=O(1)
#include<iostream>
using namespace std;
void bubblesort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
    	bool flag=1;
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
            	bool flag=0;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==false)
        {
        	break;
		}
    }
    cout<<"The array in sorted form is \n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[100];
    int size,key;
    cout<<"Enter the size of the the array \n";
    cin>>size;
    cout<<"Enter the elements \n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,size);
}
