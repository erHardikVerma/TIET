#include<iostream>
using namespace std;

int binarysearchrecursive(int arr[], int x, int left, int right)
    {
	
	if (left >right)
	{
	cout<<"error! element x not found. It's element not your ex." ;
    return -1;
	}
	
	else{
	int mid=left+(right-left)/2; //through bodmass
	
	if(arr[x]=mid)
	{
	return mid;
	}
	
	if(arr[x]>mid)
	{
	binarysearchrecursive(arr, x, mid+1, right);
    }
    
	else {
	arr[x]<mid;
	
	binarysearchrecursive(arr, x, left, mid-1);
	}
}
}
	int main(){
	int arr[]={2,,3,4,10,40};
	int x=10;
	int n=sizeof(arr)/sizeof(arr[0]);
	int result=binarysearchrecursive(arr, x, left, n-1);
	return 0;	
	}
