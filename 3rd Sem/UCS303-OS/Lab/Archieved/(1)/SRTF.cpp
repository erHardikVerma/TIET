//SRTF Scheduling algorithm:
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct process
{
    int pid;
    int at;
    int st; // start time
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
};

int main()
{
    int N;
    printf("Enter no of processes: ");
    scanf("%d", &N);

    struct process P[N];
    int curr_time = 0, idle_time = 0, completed = 0;
    int is_completed[100] = {false};

    for (int i = 0; i < N; i++){
        printf("Enter arrival time and burst time for process %d:\n", i+1);
        scanf("%d %d", &P[i].at, &P[i].bt);
        P[i].rt = P[i].bt;
        P[i].pid = i + 1;
    }

    while (completed != N){
        int min_proc = -1; // returns the index for the proc w min bt
        int min_bt = INT_MAX; // largest value int can hold
        for(int i = 0; i < N; i++){
            if (P[i].at <= curr_time && is_completed[i] == false){
                if (P[i].rt < min_bt){
                    min_bt = P[i].rt;
                    min_proc = i;
                }

                if (P[i].rt == min_bt){
                    if (P[i].at < P[min_proc].at){
                        min_bt = P[i].rt;
                        min_proc = i;
                    }
                }
            }
        }

        if (min_proc == -1){
            // no proc found w min CPU bt in ready queue till curr_time
            curr_time++;
            idle_time++;
        }

        else{
            if (P[min_proc].rt == P[min_proc].bt){
                P[min_proc].st = curr_time;
            }
            P[min_proc].rt--;
            curr_time++;

            if (P[min_proc].rt == 0){
                P[min_proc].ct = curr_time;
                P[min_proc].tat = P[min_proc].ct - P[min_proc].at;
                P[min_proc].wt = P[min_proc].tat - P[min_proc].bt;
                completed++;
                is_completed[min_proc] = true;
            }
        }
    }

    printf("\nPId\tArr\tBT\tWait\tTAT\n");
    for (int i = 0; i < N; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].at, P[i].bt, P[i].wt, P[i].tat);

    int sum_wt = 0, sum_tat = 0;
    for (int i = 0; i < N; i++){
        sum_wt += P[i].wt;
        sum_tat += P[i].tat;
    }
    printf("\nAvg waiting time: %f", (float)sum_wt / N);
    printf("\nAvg turn around time: %f", (float)sum_tat / N);
    printf("\nIdle time: %d\n", idle_time);
}
