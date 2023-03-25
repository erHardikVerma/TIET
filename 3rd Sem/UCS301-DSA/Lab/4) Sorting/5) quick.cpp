#include<iostream>
using namespace std;
int partition(int arr[],int p,int r){
	int x=arr[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}
void quick(int arr[],int p,int r){
	if(r>p){
	
	int q=partition(arr,p,r);
	quick(arr,p,q-1);
	quick(arr,q+1,r);}
}
int main(){
	int arr[8]={3,1,6,4,9,7,4,2};
	quick(arr,0,7);
	for(int i=0;i<8;i++){
		cout<<arr[i]<<endl;
	}
}
