//CPU Scheduling (FCFS):
#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int p[],int at[],int bt[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
    }
}
double sum(int arr[],int size){
    double sum=0;
    for(int k=0;k<size;k++)
        sum+=arr[k];
    return sum;
}
int main(){
    int N;
    cout<<"Enter no of processes: "<<endl;
    cin>>N;
    int at[N], bt[N], p[N], wait[N], tat[N], ct[N], idle_time=0;
    for(int i=0;i<N;i++){
        cout<<"Enter arrival and burst time for process "<<i+1<<endl;
        cin>>at[i]>>bt[i];
        p[i]=i+1;
    }
    sort(p, at, bt, N);    
    wait[0]=0;
    ct[0]=at[0]+bt[0];    
    for(int i=0;i<N;i++){
        idle_time=0;
        wait[i]=ct[i]-bt[i]-at[i];
        if(at[i+1]>ct[i])
		idle_time+=at[i+1]-ct[i];
        ct[i+1]=ct[i]+bt[i+1]+idle_time;
        tat[i]=ct[i]-at[i];
    }
    cout<<"\nProcess\tArrival\tBurst\tWait\tCompletion\tTAT\n";
    for(int i=0;i<N;i++)
        cout<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wait[i]<<"\t"<<ct[i]<<"\t\t"<<tat[i]<<endl;

    cout<<"\nAvg wait time: "<<sum(wait, N)/N;
    cout<<"\nAvg turn around time: "<<sum(tat, N)/N;  
}

