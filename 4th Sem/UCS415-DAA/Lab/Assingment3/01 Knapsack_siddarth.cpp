#include <bits/stdc++.h>
using namespace std;

// Funcition to return the max of the 2 numbers
int max(int a, int b) { return (a > b) ? a : b; }

// Main Function
int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1] = {0};

    // i is for the rows
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (j < wt[i - 1])
                K[i][j] = K[i - 1][j];
            else
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
        }
    }
    return K[n][W];
}

// Driver Code
int main()
{
    int profit[] = {2, 3, 4, 1};
    int weight[] = {3, 4, 5, 6};
    int W = 8;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << knapSack(W, weight, profit, n);

    return 0;
}
