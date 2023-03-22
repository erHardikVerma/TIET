 #include<iostream>
using namespace std;

int bsearch(int a[],int k, int h, int l);
void display();

int main()
{
	int n,k;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter the key to be searched: ";
	cin>>k;
	int h=n,l=0;
	bsearch(a,k,h,l);
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

int bsearch(int a[],int k, int h, int l)
{	
	int mid=(h+l)/2;
	if(l<=h)
	{
		if(k==a[mid])
		{
			cout<<"Element is found at index "<<mid<<endl;
		}
		else if(k<a[mid])
		{
			h=mid-1;
			return bsearch(a,k,h,l);
		}
		else
		{
			l=mid+1;
			return bsearch(a,k,h,l);
		}
	}
//	else
//	{
//	}cout<<"Element is found at index "<<mid;
//	cout<<endl;
}
