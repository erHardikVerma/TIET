#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {4,3,2,10,12,1,5,6};
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
            for (int j = i; j > 0; --j)
            {
                if (arr[j] < arr[j - 1])
                {
                    int temp1 = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
                else
                    break;
            }
        }
        else
            continue;
    }
    // Display
    cout << "The sorted array is as follows" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
