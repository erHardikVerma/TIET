#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n)
{
    int m[n][n] = {0};
    int s[n][n] = {0};

    int j, min, q;
    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            min = INT_MAX;
            for (int k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                cout << "q: " << q << endl;
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    return m[1][n - 1];
}

// Driver Code
int main()
{
    // arr array stores the size (d) of the arrays
    int arr[] = {1, 2, 3, 4};
    // size variable stores the number of Matrices to be multiplied
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size);
    return 0;
}
