#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct LinearQueueUsingLL
{
    struct Node *front;
    struct Node *rear;
    LinearQueueUsingLL()
    {
        front = rear = NULL;
    }
    void enqueue(int value)
    {
        struct Node *node = new Node(value);
        if (front == NULL)
        {
            front = node;
        }
        else
        {
            rear->next = node;
        }
        rear = node;
    }

    void dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            struct Node *del = front;
            cout << "Remove " << del->data << endl;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            delete (del);
        }
    }
    void display()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "The Queue is empty: " << endl;
        }
        else
        {
            struct Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    LinearQueueUsingLL ll;
    ll.enqueue(10);
    ll.enqueue(20);
    ll.enqueue(30);
    ll.enqueue(40);
    ll.dequeue();
    ll.dequeue();
    ll.dequeue();
    ll.dequeue();
    ll.dequeue();
    ll.display();
    return 0;
}
