#include <iostream>
#include <vector>
using namespace std;

int main()}{
	
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
int s=0;
int e=n-1;
while(s<=e){
	int mid=s+(e-s)/2;
	if(v[mid]==target){
		cout<<"The index is: "<<mid<<endl;
		return 0;
	}
	else if(v[mid]<target)}{
		e=mid-1;
	}
	else{
		s=mid+1;
	}
}
cout<<"Errrr, Sorry Not Present"<<endl;
return 0;

}
