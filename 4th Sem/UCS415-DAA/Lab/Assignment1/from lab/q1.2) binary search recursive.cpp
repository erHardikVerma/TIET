#include <iostream>
#include <vector>
using namespace std;
int binarysearch(vector <int> v,int target,int s,int e){
		while(s<e){
		
		int mid=s+(e-s)/2;
		if(v[mid]==target){
			return mid;
		}
		else if(v[mid]>target){
		return	binarysearch(v,target,s,mid-1);
		}
		else{
		return	binarysearch(v,target,mid+1,e);
		}
	}
	return -1;
}
int main(){
	
vector <int> v;
cout<<"Enter the size: ";
int n,q,target;
cin>>n;
cout<<"Enter the sorted values: "<<endl;
for(int i=0;i<n;i++){
	cin>>q;
	v.push_back(q);

}
cout<<"Enter the value you want to find"<<endl;
cin>>target;
cout<<"The Index of "<<target<<" is: "<<binarysearch(v,target,0,n-1)<<endl;
return 0;

}
