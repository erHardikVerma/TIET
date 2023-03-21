#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cout<<"Enter the number of processes"<<endl;
    cin>>n;
    int at[n];
    int bt[n];
    int ct[n];
    int wt[n];
    int tat[n];
    cout<<"Enter arrival times: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>at[i];
    }
    
    cout<<"Enter Burst time: "<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>bt[i];
    }
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            ct[i]=bt[i]+at[i];
        }
        if(sum<at[i])
        {
            sum=sum+(at[i]-sum);
        }
        ct[i]=sum+bt[i];
        sum=ct[i];
    }
    //Total turn-around time
    for(int i=0;i<n;++i)
    {
        tat[i]=ct[i]-at[i];
    }
    //Waiting time
    for(int i=0;i<n;++i)
    {
        wt[i]=tat[i]-bt[i];
    }
    
    //Printing 
    cout<<"P-id\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"WT\t"<<"TAT"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<(i+1)<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
    }
    return 0;
}
