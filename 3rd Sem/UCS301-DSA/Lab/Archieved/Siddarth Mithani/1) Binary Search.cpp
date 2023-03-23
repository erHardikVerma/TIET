#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//The following function returns the index of the element if present in the array or
//If not present the function returns -1
int binary_search(int arr[],int x,int low,int high)
{
	if(high>low)
	{
		int mid=(low+high)/2;
		if(x==arr[mid])
			return mid;
		else if(x<arr[mid])	
			return binary_search(arr,x,low,mid-1);
		else
			return binary_search(arr,x,mid+1,high);
	}
	return -1;
}

int main()
{
	time_t start,end;
	time(&start);
	int arr[]={10,20,30,40,50,60,70,80,90,100};
	int size_of_array=sizeof(arr)/sizeof(arr[0]);//10
	
	cout<<"Enter the element to be searched"<<endl;
	int x;
	cin>>x;
	
	int index=binary_search(arr,x,0,size_of_array-1);
	if(index==-1)
		cout<<"The element is not present in the array"<<endl;
	else
		cout<<"Element found at index: "<<index<<" in the array"<<endl;
	time(&end);
	double time_taken=double(end-start);
	cout<<"Time taken by the program to execute is: "<<time_taken<<"sec"<<endl;
}
