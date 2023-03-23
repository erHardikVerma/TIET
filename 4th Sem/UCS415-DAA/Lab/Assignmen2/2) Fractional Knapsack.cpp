#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the jobs in decreasing order of their profit
void Item_Sort(int item_value[], int item_weight[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((item_value[j] / item_weight[j]) < (item_value[j + 1] / item_weight[j + 1]))
            {
                swap(&item_value[j], &item_value[j + 1]);
                swap(&item_weight[j], &item_weight[j + 1]);
            }
}

// Main greedy function to solve problem
double fractionalKnapsack(int item_value[], int item_weight[], int w, int n)
{
    // Sorting Item on basis of ratio
    Item_Sort(item_value, item_weight, n);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < n; i++)
    {
        // adding item completely if it wont overflow
        if (item_weight[i] <= w)
        {
            w -= item_weight[i];
            finalvalue += item_value[i];
        }

        // adding the fractional part of it
        else
        {
            finalvalue += item_value[i] * ((double)w / (double)item_weight[i]);
            break;
        }
    }

    return finalvalue;
}

// Driver code
int main()
{
    int item_value[] = {60, 100, 120};
    int item_weight[] = {10, 20, 30};

    int W = 50;

    int n = sizeof(item_value) / sizeof(item_value[0]);

    // Function call
    cout << fractionalKnapsack(item_value, item_weight, W, n);
    return 0;
}
