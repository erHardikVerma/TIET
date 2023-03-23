//Memory management first fit case
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
		int naflag=false;
		for(int j=0;j<n;++j)
		{
			if(p[i]<b[j]&&flag[j]==1)
			{
				cout<<(j+1)<<endl;
				flag[j]=0;
				b[j]=b[j]-p[i];
				naflag=true;
				break;
			}
		}
		if(naflag==false)
			cout<<"Not allocated"<<endl;
	}
	return 0;
}
