// To calculate the minimum number of coins required to make the required sum
#include <bits/stdc++.h>
using namespace std;

int getMinCoinsReq(int w, int coins[], int n)
{
    int dp[n][w + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == 0)
                dp[i][0] = 0;
            else if (i == 0 && j != 0)
            {
                if (j % coins[i] == 0)
                    dp[i][j] = j / coins[i];
                else
                    dp[i][j] = 100;
            }
            else
            {
                if (j < coins[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout << dp[i][j] << "   ";
        }
        cout << endl;
    }
    return dp[n - 1][w];
}

// Driver Code
int main()
{
    int coins[] = {3, 5, 6, 9};
    int n = sizeof(coins) / sizeof(coins[0]);
    int W = 10;
    cout << getMinCoinsReq(W, coins, n) << endl;
}
