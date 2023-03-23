#include <iostream>
using namespace std;

//Assumption that the activities are already sorted according to finish time if 
void ActivitySelection(int start[], int finish[], int n)
{
    int i, j;
    cout << "Following activities are selected" << endl;
    i = 0;
    cout << i << " ";
    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            cout << j << " ";
            i = j;
        }
    }
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    ActivitySelection(start, finish, n);
    return 0;
}
