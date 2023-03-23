//Reversing a string using stack
#include <iostream>
#include<string.h>
using namespace std;
struct StacksUsingArrays
{
public:
    int size = 0;
    int top = 0;
    StacksUsingArrays(int size)
    {
        this->size = size;
        top = size;
    }
    // Function to push an element onto the stack
    void push(char *arr,char data)
    {
        if (top == 0)
        {
            cout << "Error: Overflow" << endl;
            return;
        }
        else
        {
            --top;
            arr[top]=data;
        }
    }
    //Printing the reversed string
    void display(char *arr)
    {
        if (top == size)
        {
            cout << "The stack is empty: " << endl;
            return;
        }
        else
        {
            for (int i = top; i < size; i++)
            {
                cout << arr[i];
            }
        }
    }
};
int main()
{
    string str;
    cout << "Enter the string you want to reverse" << endl;
    cin >> str;
    int len=str.length();
    StacksUsingArrays obj(len);
    char arr[len];
    for (int  i = 0; i < len; i++)
    {
        char ch=str.at(i);
        obj.push(arr,ch);
    }
    obj.display(arr);
    return 0;
}
