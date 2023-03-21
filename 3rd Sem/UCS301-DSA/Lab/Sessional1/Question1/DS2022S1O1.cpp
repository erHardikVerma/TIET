#include <iostream>
using namespace std;

void SwapValue(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

int main() 
{
    int n,r,i,j,k;
    cin>>n;
    cin>>r;
    int arr[n][n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                cin>>arr[i][j][k];
    
    while(r--)
    {
        int temp= 0;
        i=j=k=0;
        while(j<n)
        {
            for(i=0;i<n;i++)
            {
                // temp+=arr[i][j][i];
                // arr[i][j][i]=temp-arr[i][j][i];
                // temp-=arr[i][j][i];
                SwapValue(arr[i][j][i],temp);
            }
            j++;
            if(j<n)
            {
                for(i=n-1;i>=0;i--)
                {
                    // temp+=arr[i][j][i];
                    // arr[i][j][i]=temp-arr[i][j][i];
                    // temp-=arr[i][j][i];
                    SwapValue(arr[i][j][i],temp);
                }
            }
            j++;
        }

        arr[0][0][0]=temp;
        i=j=k=0;
        while(j<n)
        {
            for(i=0;i<n;i++)
            {
                // temp+=arr[n-i-1][j][i];
                // arr[n-1-i][j][i]=temp-arr[n-1-i][j][i];
                // temp-=arr[n-1-i][j][i];
                SwapValue(arr[n-1-i][j][i],temp);
            }
            j++;
            if(j<n)
            {
                for(i=n-1;i>=0;i--)
                {
                // temp+=arr[n-1-i][j][i];
                // arr[n-1-i][j][i]=temp-arr[n-1-i][j][i];
                // temp-=arr[n-1-i][j][i];
                SwapValue(arr[n-1-i][j][i],temp);
                }
            }
            j++;
        }
        arr[n-1][0][0]=temp;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                cout<<arr[i][j][k]<<" ";
	
	return 0;
}
