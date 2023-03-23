#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the jobs in decreasing order of their profit
void Job_sort(int job_id[], int job_deadline[], int job_profit[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (job_profit[j] < job_profit[j + 1])
            {
                swap(&job_id[j], &job_id[j + 1]);
                swap(&job_profit[j], &job_profit[j + 1]);
                swap(&job_deadline[j], &job_deadline[j + 1]);
            }
}

// Returns maximum profit from jobs
void printJobScheduling(int job_id[], int job_deadline[], int job_profit[], int n)
{
    // Sort all jobs according to decreasing order of profit
    Job_sort(job_id, job_deadline, job_profit, n);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job
        for (int j = min(n, job_deadline[i]) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << job_id[result[i]] << " ";
}

// Driver's code
int main()
{
    int job_id[] = {1, 2, 3, 4, 5};
    int job_deadline[] = {2, 1, 2, 1, 3};
    int job_profit[] = {100, 19, 27, 25, 15};

    int n = 5;
    cout << "Following is maximum profit sequence of jobs \n" << endl;

    // Function call
    printJobScheduling(job_id, job_deadline, job_profit, n);
    return 0;
}

// Sorted array
// 1   2   100
// 3   2   27
// 4   1   25
// 2   1   19
// 5   3   15
