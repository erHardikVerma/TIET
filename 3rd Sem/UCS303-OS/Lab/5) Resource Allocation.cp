#include<iostream>
using namespace std;

int main()
{
	int m=0;
	int n=0;
	cout<<"Enter the number of processes: ";
	cin>>n;
	cout<<"Enter the number of resources: ";
	cin>>m;
// Allocation Matrix
	cout<<"Enter the allocation matrix"<<endl;
	int alloc[n][m]; 
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>alloc[i][j];
		}
	}
// MAX Matrix
cout<<"Enter the Max matrix"<<endl;
	int max[n][m];
		for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cin>>max[i][j];
		}
	}
					
//To calculate the total available resources
	int total[1][m];
	cout<<"Enter the total number of each resources: "<<endl;
	for(int i=0;i<m;++i)
	{
		cin>>total[1][i];
	}
	
	int avail[m];
	for(int i=0;i<m;++i)
	{
		int sum=0;
		for(int j=0;j<n;++j)
		{
			sum=sum+alloc[j][i];
		}
		avail[i]=total[1][i]-sum;
	}
	
	//F array is used to chcek which process have finished
	int f[n];
	for (int k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	//Calculating the need 
	int need[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	
	int ans[n];//To store the sequence
	int ind=0;
	int y = 0;
	for (int k = 0; k < n; k++) 
	{
		for (int i = 0; i < n; i++) 
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (int j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0) 
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}		
		}
	}
// To check if sequence is safe or not	
	int flag = 1;
	for(int i=0;i<n;++i)
	{
		cout<<f[i]<<endl;
	}

	if(flag==1)
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (int i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[n - 1] <<endl;
	}
	return 0;
}
