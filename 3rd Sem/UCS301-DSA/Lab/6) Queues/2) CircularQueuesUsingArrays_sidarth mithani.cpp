#include <iostream>
using namespace std;
class Queue
{
public:
  int rear, front;

  // Circular Queue
  int size;
  int *arr;
  Queue(int s)
  {
    front = rear = -1;
    size = s;
    arr = new int[s];
  }

  void enQueue(int value);
  int deQueue();
  void displayQueue();
};

// Function to add an element to the circular queue
void Queue::enQueue(int value)
{
  if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
  {
    cout << "The Queue is Full" << endl;
    return;
  }
  // IF the Queue is empty
  else if (front == -1)
  {
    front = rear = 0;
    arr[rear] = value;
  }

  else if (rear == size - 1 && front != 0)
  {
    rear = 0;
    arr[rear] = value;
  }

  else
  {
    arr[++rear] = value;
  }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
  if (front == -1)
  {
    cout << "The queue is already empty" << endl;
    return -1;
  }

  int data = arr[front];
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == size - 1)
    front = 0;
  else
    front++;
  return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
  if (front == -1)
  {
    cout << "The queue is empty" << endl;
    return;
  }
  if (rear >= front)
  {
    for (int i = front; i <= rear; i++)
      cout << arr[i] << endl;
  }
  else
  {
    for (int i = front; i < size; i++)
      cout << arr[i] << endl;
    for (int i = 0; i <= rear; i++)
      cout << arr[i] << endl;
  }
}

/* Driver of the program */
int main()
{
  Queue q(7);
  q.enQueue(10);
  q.enQueue(20);
  q.enQueue(30);
  q.enQueue(40);
  q.enQueue(50);
  q.enQueue(60);
  q.enQueue(70);
  q.displayQueue();
  int x = q.deQueue();
  cout << "Element Removed " << x << endl;
  q.displayQueue();
  return 0;
}
