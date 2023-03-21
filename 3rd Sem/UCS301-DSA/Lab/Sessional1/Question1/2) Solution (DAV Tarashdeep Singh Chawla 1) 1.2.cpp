#include <iostream>
using namespace std;

//for sessional 1 (question 1) (solution1)
//by DAV Tarashdeep Singh Chawla

int main() 
{
    int n,k;
    cin>>n;
    cin>>k;
    int arr[n][n][n];
    for(int p=0;p<n;p++)
        for(int q=0;q<n;q++)
            for(int r=0;r<n;r++)
                cin>>arr[p][q][r];
    
    while(k--)
    {
        int update= 0;
        int a=0, b=0, c=0;
        while(b<n)
        {
            for(a=0;a<n;a++)
            {
                update+=arr[a][b][a];
                arr[a][b][a]=update-arr[a][b][a];
                update-=arr[a][b][a];
            }
            b++;
            if(b<n)
            {
                for(a=n-1;a>=0;a--)
                {
                    update+=arr[a][b][a];
                    arr[a][b][a]=update-arr[a][b][a];
                    update-=arr[a][b][a];
                }
            }
            b++;
        }

        arr[0][0][0]=update;
        a=b=c=0;
        while(b<n)
        {
            for(a=0;a<n;a++)
            {
                update+=arr[n-a-1][b][a];
                arr[n-a-1][b][a]=update-arr[n-a-1][b][a];
                update-=arr[n-a-1][b][a];
            }
            b++;
            if(b<n)
            {
                for(a=n-1;a>=0;a--)
                {
                update+=arr[n-1-a][b][a];
                arr[n-1-a][b][a]=update-arr[n-1-a][b][a];
                update-=arr[n-1-a][b][a];
                }
            }
            b++;
        }
        arr[n-1][0][0]=update;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cout<<arr[i][j][k]<<" ";
	
	return 0;
}
