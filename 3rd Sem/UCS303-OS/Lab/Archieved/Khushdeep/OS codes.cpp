Bankers algorithm


#include <iostream>
using namespace std;
int main(){
    int i,j,k;
    int n=5;
    int m=3;
    

    int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int alloted[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};\
    int aval[3] = {3,3,2};
    int stat[n] = {0};
    int seq[n] = {0};
    int x = 0;
    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloted[i][j];
        }
    }
    int y=0;
    for(int k=0;k<5;k++){
        for(int i=0;i<n;i++){
            if(stat[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>aval[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    seq[x++] = i;
                    for(int y=0;y<m;y++){
                        aval[y] +=alloted[i][y];
                    }
                    stat[i]=1;
                }
            }
        }
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(stat[i] == 0){
            flag = false;
            cout<<"system is in deadlock";break;
            break;
        }
    }
    if(flag = true){
        cout<<"sysetm is in safe state and the sequence is"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<"P"<<seq[i]<<" ->";
        }
        cout<<"P"<<seq[n-1]<<endl;
    }
    return











FCFS cpu sscheduling
#include <iostream>
using namespace std;

void findwt(int process[],int n,int bt[],int wt[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
}
void findtat(int process[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = bt[i]+wt[i];
    }
}
void findavgtime(int process[],int n,int bt[]){
    int wt[n],tat[n],total_wt = 0,total_tat = 0;
    findwt(process,n,bt,wt);
    findtat(process,n,bt,wt,tat);
    cout<<"processes "<<" burts time "<<" waiting time "<<" turn around time \n";
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
        cout<<"   "<<i+1<<"\t\t"<<bt[i]<<"\t    "<<wt[i]<<"\t\t  "<<tat[i]<<endl;
    }
    cout<<"Average waiting time = "<<(float)total_wt/(float)n<<endl;
    cout<<"Average turn around time = "<<(float)total_tat/(float)n;
}
int main() {
    int processes[] = {1,2,3};
    int n = sizeof processes/sizeof processes[0];
    int burst_time[] = {10,5,8};
    findavgtime(processes,n,burst_time);
    return 0;
}








ROUND ROBIN CPU SCH

 #include <iostream>

/*at = Arrival time,
bt = Burst time,
time_quantum= Quantum time
tat = Turn around time,
wt = Waiting time*/

using namespace std;

int main(){
	int i,n,time,remain,temps=0,time_quantum;

	int wt=0,tat=0;

	cout<<"Enter the total number of process="<<endl;
	cin>>n;

	remain=n;
	// assigning the number of process to remain variable

	int at[n];
	int bt[n];
	int rt[n];


	cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;
	for(i=0;i<n;i++)
	{
	  cout<<"Arrival time for process "<<i+1<<endl;
		cin>>at[i];
		cout<<"Burst time for process "<<i+1<<endl;
		cin>>bt[i];
		rt[i]=bt[i];
	}

	cout<<"Enter the value of time QUANTUM:"<<endl;
	cin>>time_quantum;

	cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
		
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
		
			time += time_quantum;
		
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			//Desplaying the result of wating, turn around time:
			printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
			cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n<<endl;;

	return 0;
}








FIRST FIT


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void firstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
                allocation[i] = j;
                blocksize[j]-=processsize[i];
                break;
            }
        }
    }
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

int main() {
    int blocksize[]={100, 500, 200, 300, 600};
    int processsize[]={212, 417, 112, 426};
    int m = sizeof(blocksize)/sizeof(blocksize[0]);
    int n = sizeof(processsize)/sizeof(processsize[0]);
    firstfit(blocksize,m,processsize,n);
    return 0;
}







WORST FIT 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void worstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int wrstidx = -1;
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
               if(wrstidx==-1){
                   wrstidx = j;
               }
               else if(blocksize[wrstidx]<blocksize[j]){
                   wrstidx = j;
                   
               }
            }
        }
        if(wrstidx !=-1){
            allocation[i] = wrstidx;
            blocksize[wrstidx] -= processsize[i];
        }
    }
   
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

int main() {
    int blocksize[]={100, 500, 200, 300, 600};
    int processsize[]={212, 417, 112, 426};
    int m = sizeof(blocksize)/sizeof(blocksize[0]);
    int n = sizeof(processsize)/sizeof(processsize[0]);
    worstfit(blocksize,m,processsize,n);
    return 0;
}







BEST FIT

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bestfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int bstidx = -1;
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
               if(bstidx==-1){
                   bstidx = j;
               }
               else if(blocksize[bstidx] > blocksize[j]){
                   bstidx = j;
                   
               }
            }
        }
        if(bstidx !=-1){
            allocation[i] = bstidx;
            blocksize[bstidx] -= processsize[i];
        }
    }
   
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

int main() {
    int blocksize[]={100, 500, 200, 300, 600};
    int processsize[]={212, 417, 112, 426};
    int m = sizeof(blocksize)/sizeof(blocksize[0]);
    int n = sizeof(processsize)/sizeof(processsize[0]);
    bestfit(blocksize,m,processsize,n);
    return 0;
}







fcfs os disk managment

 #include <iostream>
using namespace std;
int size = 8;

void fcfs(int arr[],int head){
    int seekcount = 0;
    int current_track;
    int distance;
    for(int i = 0;i<size;i++){
        current_track = arr[i];
        distance = abs(current_track - head);
        seekcount += distance;
        head = current_track;
    }
    cout<<"Total no. of seek operations: "<<seekcount<<endl;
    cout<<"Seek sequence is: "<<endl;
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}

int main() {
    int arr[size] = {98,183,37,122,14,65,67};
    int head = 53;
    fcfs(arr,head);

    return 0;
}







sstf os disk scheduling code

 #include <iostream>
using namespace std;

void calculatediff(int request[],int head,int diff[][2],int n){
    for(int i=0;i<n;i++){
        diff[i][0] = abs(head - request[i]);
    }
}
int findmin(int diff[][2],int n){
    int index = -1;
    int minimum = 1e9;
    for(int i = 0; i < n; i++){
        if (!diff[i][1] && minimum > diff[i][0]){
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestseektimefirst(int request[],int head,int n){
    if(n == 0){
        return;
    }
    int diff[n][2] = {{0,0}};
    int seekcount = 0;
    int seeksequence[n+1] = {0};
    for(int i=0;i<n;i++){
        seeksequence[i] = head;
        calculatediff(request,head,diff,n);
        int index = findmin(diff,n);
        diff[index][1] = 1;
        seekcount += diff[index][0];
        head = request[index];
    }
        seeksequence[n] = head;
        cout<<"The total no. of head movements are: "<<seekcount<<endl;
        cout<<"The seek sequence is: "<<endl;
        for(int i=0;i<=n;i++){
            cout<<seeksequence[i]<<endl;
        }
}

int main() {
    int n = 7;
    int process[n] = {98,183,37,122,14,65,67};
    
    shortestseektimefirst(process,53,n);

    return 0;
}








SJF CPU SCHEDULING

#include <bits/stdc++.h>
using namespace std;

struct Process {
   int pid;
   int bt; 
   int art; 
};
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n; i++)
   tat[i] = proc[i].bt + wt[i];
}

void findWaitingTime(Process proc[], int n, int wt[]) {
   int rt[n];
   for (int i = 0; i < n; i++)
   rt[i] = proc[i].bt;
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      
      rt[shortest]--;
      minm = rt[shortest];
      if (minm == 0)
         minm = INT_MAX;
         
         if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            
            wt[shortest] = finish_time -
            proc[shortest].bt -
            proc[shortest].art;
            if (wt[shortest] < 0)
               wt[shortest] = 0;
         }
         
         t++;
   }
}

void findavgTime(Process proc[], int n) {
   int wt[n], tat[n], total_wt = 0,
   total_tat = 0;
   
   findWaitingTime(proc, n, wt);
   
   findTurnAroundTime(proc, n, wt, tat);
   cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time"<<endl;
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
   }
   cout << "Average waiting time = " << (float)total_wt /(float)n; cout << "  Average turn around time = " << (float)total_tat / (float)n;
}

int main() {
   Process proc[] = { { 1, 5, 1 }, { 2, 3, 1 }, { 3, 6, 2 }, { 4, 5, 3 } };
   int n = sizeof(proc) / sizeof(proc[0]);
   findavgTime(proc, n);
   return 0;
}






