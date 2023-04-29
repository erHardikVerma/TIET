#include<iostream>
#include<algorithm>
using namespace std;

int knapsack_0_1(int P[], int Wt[], int M, int n){
    int K[n+1][M+1];
    for(int i=0;i<=n;i++){
        for(int W=0;W<=M;W++){
            if(i==0 || W==0){
                K[i][W]=0;
            }
            else if(W>=Wt[i-1]){
                K[i][W]= max(K[i-1][W], P[i-1] + K[i-1][W - Wt[i-1]]);
            }
            else{
                K[i][W]=K[i-1][W];
            }
        }
    }
    for(int i=0;i<=n;++i)
    {
    	for(int j=0;j<=M;++j)
    	{
    		cout<<K[i][j]<<" ";
		}
		cout<<endl;
	}
    return K[n][M];
}

int main(){
    int P[]={2,3,4,1};
    int Wt[]={3,4,5,6};
    int n=4;
    int M=8;
    cout<<knapsack_0_1(P,Wt,M,n);
}
