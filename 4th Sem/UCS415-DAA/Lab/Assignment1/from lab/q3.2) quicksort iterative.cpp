#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int partition(int array[], int l, int h) {
    
  int pivot = array[h];
  
  int i = (l - 1);
  for (int j = l; j < h; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }
  

  swap(array[i + 1], array[h]);
  
  return (i + 1);
}

void quickSort(int array[], int l, int h) {
 int stack[h-l+1]; 
  int top = -1; 
  stack[++top]=l; 
  stack[++top]=h; 
  while(top >= 0) 
  { 
    h = stack[top--]; 
    l = stack[top--]; 
    int p = partition(array, l, h); 
    if(p-1>l) 
    { 
      stack[++top] = l; 
      stack[++top] = p - 1; 
    } 
    if(p+1<h) 
    { 
      stack[++top] = p + 1; 
      stack[++top] = h; 
    } 
  } 
}
int main() {
  	
	cout<<"Enter the size: ";
	int n,q;
	cin>>n;
	int arr[n];
	cout<<"Enter the values you want to sort: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];


	}
	
	  quickSort(arr,0,n-1);
	
	  cout << "Sorted array: \n";
	  for (int i = 0; i < n; i++){
	  
	    cout << arr[i] << " ";
		}
	
	  return 0;
}
