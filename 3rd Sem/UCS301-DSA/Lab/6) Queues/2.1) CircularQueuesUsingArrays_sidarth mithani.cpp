// Circular Queue using arrays
#include <iostream>
using namespace std;

struct CircularQueue
{
    int front;
    int rear;
    int size;
    int *arr;
    CircularQueue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    void enqueue(int data)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Overflow" << endl;
            return;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }

            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << arr[front] << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
                front = (front + 1) % size;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "The queue is emptyy" << endl;
            return;
        }

        int temp = front;
        while (temp % size != rear)
        {
            cout << arr[temp] << " ";
            ++temp;
        }
        cout << arr[temp] << endl;
    }
};

int main()
{
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.display();
}
