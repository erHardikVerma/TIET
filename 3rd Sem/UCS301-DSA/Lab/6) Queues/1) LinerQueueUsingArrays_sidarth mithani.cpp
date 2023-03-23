#include <iostream>
using namespace std;
class LinearQueue
{
public:
    int size;
    int *arr;
    int front = -1;
    int rear = -1; 
    LinearQueue()
    {
        cout << "Enter the size of the linear queue: " << endl;
        cin >> this->size;
        arr = new int[size];
    }
    void enqueue(int data)
    {
        if (rear == (size - 1))
        {
            cout << "The queue is full" << endl;
            return;
        }
        else
        {
            if (rear == -1 && front == -1)
            {
                ++front;
            }
            arr[++rear] = data;
        }
    }

    void dequeue()
    {
        if (front == rear + 1)
        {
            cout << "The Queue is empty" << endl;
        }
        else
        {
            cout << "Removed: " << arr[front] << endl;
            ++front;
        }
    }

    void print()
    {
        if (front == rear + 1)
        {
            cout << "The Queue is Empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
};
int main()
{
    LinearQueue obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.enqueue(40);
    obj.print();
    return 0;
}
