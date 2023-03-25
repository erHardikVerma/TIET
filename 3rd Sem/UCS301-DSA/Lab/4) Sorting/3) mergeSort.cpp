#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub){
	   

    int i, j, k;  
    int n1 = mid - lb + 1;    
    int n2 = ub - mid;    
      
    int LeftArray[n1], RightArray[n2]; //temporary arrays  
      
      
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = arr[lb + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = arr[mid + 1 + j];    
      
    i = 0, /* initial index of first sub-array */  
    j = 0; /* initial index of second sub-array */   
    k = lb;  /* initial index of merged sub-array */  
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            arr[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            arr[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        arr[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        arr[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
void mergesort(int arr[],int lb,int ub){
	if(lb<ub){
	int mid=(lb+ub)/2;
	mergesort(arr,lb,mid);
	mergesort(arr,mid+1,ub);
	merge(arr,lb,mid,ub);
	cout<<lb<<ub<<endl;
	}
}
int main()
{
	int arr[]={2,5,3,6,7,8,1,9,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	int lb=0;
	int ub=size-1;
	mergesort(arr,lb,ub);
	for(int i=0;i<9;i++){
		cout<<arr[i]<<endl;
	}
}
