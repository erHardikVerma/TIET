//Best fit case
#include<iostream>
using namespace std;
int main()
{
	//n is the total number of memory blocks
	int n=5;
	//b is to store the memory available
	int b[] = {100,500,200,300,600};
	//p is to store the memory that is required by each process
	int p[] = {213,417,112,426};
	int flag[5]={1,1,1,1,1};
	//First fit
	for(int i=0;i<4;++i)
	{
		int diff[]={0,0,0,0};
		for(int j=0;j<n;++j)
		{
			if(flag[j]==1)
				diff[j]=b[j]-p[i];	
			else
				diff[j]=9999;		
		}
		//Finding the smallest difference
		int smallest=9998;
		int smallest_index=0;
		for(int k=0;k<n;++k)
		{
			if(diff[k]<smallest&&diff[k]>0)
			{
				smallest=diff[k];
				smallest_index=k;
			}
		}
		//Updating the memory block
		if(smallest==9999||smallest<0)
			cout<<"Not allocated"<<endl;
		else
		{
			cout<<(smallest_index+1)<<endl;
			flag[smallest_index]=0;
		}
	}
	return 0;
}
