#include<iostream>
using namespace std;
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	
}
int main(){
	int a[]={18,45,3212,5,3,5,4,666,2,2};
	int size=sizeof(a)/sizeof(a[0]);
	
	for(int i=size-1;i>-1;i--){
		int flag=0;
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				swap(a,j,j+1);
				
				flag=flag+1;
			}}
		if(flag==0){
			break;
			}
		
	}
	for(int i=0;i<size;i++){
		cout<<a[i]<<endl;
	}
}
