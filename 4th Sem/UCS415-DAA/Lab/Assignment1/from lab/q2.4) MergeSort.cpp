#include<iostream>
using namespace std;

int mergeSort(int a[], int h, int l);
int merge(int a[], int h, int l);
void display();

int main()
{
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int h=n,l=0;
	mergeSort(a,h,l);
	display();
	return 0;
}

void display()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int mergeSort(int a[],int h, int l)
{
	mid=(h+l)/2;
	
	return 
}

int merge(int a[], int h, int l)
{
	
}
