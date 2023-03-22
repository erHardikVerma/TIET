#include<iostream>
using namespace std;

int binarysearch(int a[],int first, int last, int n){
int mid=(first+last)/2;
if(last<first)
return -1;
else if(a[mid]>n)
binarysearch(a,first,mid-1,n);
else if(a[mid]<n)
binarysearch(a,mid+1,last,n);
else if(a[mid==n])
return(a[mid]);
return 0;
}

int searchelement(int a[],int size,int n){
	int first=0;
	int last=size-1;
	int result;
	result=binarysearch(a,first,last,n);
	return result;       
}

int main(){
	int a[100],i,size,n,t,result;
	cout<<"Total number of elements in the array:";
	cin>>t;
	cout<<"Enter the elements of the array:\n";
	for(i=0;i<t;i++){
		cin>>a[i];
	}
	cout<<"Enter the element to be searched:\n";
	cin>>n;
	size=sizeof(a)/sizeof(int);
	cout<<size;
	result=searchelement(a,size,n);
	cout<<result;
	return 0;
}
