#include <iostream>
using namespace std;
struct StacksUsingArrays
{
public:
    int size = 0;
    int top = 0;
    //Parameterized Constructor
    StacksUsingArrays(int size)
    {
        this->size = size;
        top = size;
    }

    // Function to push an element onto the stack
    void push(int *arr,int data)
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

    //Fucntion to pop an element from the top of the stack
    void pop(int *arr)
    {
        if(top==size)
        {
            cout<<"Error:Underflow"<<endl;
        }
        else
        {
            cout<<"Popped Element is: "<<arr[top]<<endl;
            ++top;
        }
    }

    void display(int *arr)
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
                cout << arr[i] << endl;
            }
        }
    }
};
int main()
{
    int size;
    cout << "Enter the size of the stack: " << endl;
    cin >> size;
    //Creating a stuct object
    StacksUsingArrays obj(size);
    int arr[size];
    obj.push(arr,10);
    obj.push(arr,20);
    obj.push(arr,30);
    obj.push(arr,40);
    obj.display(arr);
    // obj.pop(arr);
    // obj.pop(arr);
    // obj.pop(arr);
    // obj.pop(arr);
    // obj.pop(arr);
    // obj.pop(arr);
    // obj.display(arr);
}
