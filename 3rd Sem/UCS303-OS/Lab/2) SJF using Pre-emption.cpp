//Program to Implement SJF using Pre-emption
#include<iostream>
using namespace std;
int Process[20][7];
int sum(int size)
{
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=sum+Process[i][3];
    }
    return sum;
}
int minimum(int size)
{
    int index=0;
    int min=0;
    for (int i = 0; i < size; i++)
    {
        if(Process[i][3]>0)
        {
            min=Process[i][3];
            index=i;
            break;
        }
    }
    for (int i = 1; i < size; i++)
    {
        if (Process[i][3]>0&&Process[i][3]<min)
        {
            min=Process[i][3];
            index=i;
        }
    }
    return index;
}
int checkifprocessArrived(int timer,int pointer, int size)
{
    int increment=0;
    for(int i=0;i<size;++i)
    {
        if(timer==Process[i][1])
        {
            increment=increment+1;
        }
    }
    return increment;
}
int main()
{
    int n;
    cout<<"Enter the number of processes: "<<endl;
    cin>>n;
    cout<<"Enter the arrival and Burst Times"<<endl;
    for (int i = 0; i < n; i++)
    {
        //0-Index
        //1-Arrival Time
        //2-Burst Time
        //3-Remaining Burst Time
        //4-Completion Time
        //5-Total Turn Around Time
        //6-Waiting Time
        Process[i][0]=(i+1);
        cin>>Process[i][1];
        cin>>Process[i][2]; 
        Process[i][3]=Process[i][2];
    }
    //Sorting the AT into a new 2D array according to increasing arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Process[j][1] > Process[j + 1][1])
                {
                    int temp0=Process[j][0];
                    Process[j][0]=Process[j+1][0];
                    Process[j+1][0]=temp0;

                    int temp1=Process[j][1];
                    Process[j][1]=Process[j+1][1];
                    Process[j+1][1]=temp1;

                    int temp2=Process[j][2];
                    Process[j][2]=Process[j+1][2];
                    Process[j+1][2]=temp2;
                    
                    int temp3=Process[j][3];
                    Process[j][3]=Process[j+1][3];
                    Process[j+1][3]=temp3;

                }
        }
    }
    //Below flag is to check if all the processes have terminated successfully
    int flag=0;
    //Timer variable is used to keep check of the time
    int timer=0;
    int pointer=0;
    while (flag!=1)
    {
        //Pointer for a new Array
        int inc=checkifprocessArrived(timer,pointer,n);
        pointer=pointer+inc;

        //Index gets the value of the function that needs to be decremented
        int index=minimum(pointer);

        cout<<"Timer: "<<timer<<" to "<<(timer+1)<<endl;
        cout<<"Process Number"<<Process[index][0]<<" is in CPU\n"<<endl;

        //Reducing the Remaining Burst Time by 1
        --Process[index][3];
        //Increasing the Counter
        ++timer;

        //If the sum of the Remaining BT is 0 then while loop will end
        if (sum(n)==0)
        {
            flag=1;
        }
        //Below comment is used to just check the working
        // cout<<"Index\tAT\tBT\tRemBT"<<endl;
        // for (int i = 0; i < pointer; i++)
        // {
        //     cout<<Process[i][0]<<"\t"<<Process[i][1]<<"\t"<<Process[i][2]<<"\t"<<Process[i][3]<<endl;
        // }
        
        //Check to calculate the completion time
        if(Process[index][3]==0)
        {
            Process[index][4]=timer;
        }
    }

    //For the Calculation of TAT
    for (int i = 0; i < n; i++)
    {
        Process[i][5]=Process[i][4]-Process[i][1];
    }

    //For Calculation of WT
    for (int i = 0; i < n; i++)
    {
        Process[i][6]=Process[i][5]-Process[i][2];
    }


    //Resorting the Process According to the Process Number
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Process[j][0] > Process[j + 1][0])
                {
                    int temp0=Process[j][0];
                    Process[j][0]=Process[j+1][0];
                    Process[j+1][0]=temp0;

                    int temp1=Process[j][1];
                    Process[j][1]=Process[j+1][1];
                    Process[j+1][1]=temp1;

                    int temp2=Process[j][2];
                    Process[j][2]=Process[j+1][2];
                    Process[j+1][2]=temp2;
                    
                    int temp4=Process[j][4];
                    Process[j][4]=Process[j+1][4];
                    Process[j+1][4]=temp4;

                    int temp5=Process[j][5];
                    Process[j][5]=Process[j+1][5];
                    Process[j+1][5]=temp5;
                    
                    int temp6=Process[j][6];
                    Process[j][6]=Process[j+1][6];
                    Process[j+1][6]=temp6;

                }
        }
    }   
    //Final Output   
    cout<<"\nIndex\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<Process[i][0]<<"\t"<<Process[i][1]<<"\t"<<Process[i][2]<<"\t"<<Process[i][4]<<"\t"<<Process[i][5]<<"\t"<<Process[i][6]<<endl;
    }
    return 0;
}
