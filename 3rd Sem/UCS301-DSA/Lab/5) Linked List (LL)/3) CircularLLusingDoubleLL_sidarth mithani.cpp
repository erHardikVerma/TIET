#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
struct CircularLLusingDoubleLL
{
    struct Node *head;
    CircularLLusingDoubleLL()
    {
        head = NULL;
    }
    // Fuction to enter an element at the begenning of the circular linked list
    void pushbeg(int data)
    {
        struct Node *newnode = new Node(data);
        if (head == NULL)
        {
            newnode->next = newnode;
            newnode->prev = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = head->prev;
            head->prev = newnode;
            newnode->prev->next = newnode;
        }
        head = newnode;
    }

    // Function to insert an element at the end of a circular doubly linked list
    void pushend(int data)
    {
        struct Node *newnode = new Node(data);
        if (head == NULL)
        {
            newnode->next = newnode->prev = newnode;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = head->prev;
            newnode->prev->next = newnode;
            head->prev = newnode;
        }
    }

    // Function to insert an element after a specific value in the Circular Doubly linked list
    void pushmid(int data, int value)
    {
        struct Node *node = new Node(data);
        struct Node *temp = head;
        while (temp->next != head && temp->data != value)
            temp = temp->next;
        if (temp->next == head && temp->data != value)
        {
            cout << "The given element is not present in the linked list" << endl;
        }
        else
        {
            node->prev = temp;
            node->next = temp->next;
            temp->next->prev = node;
            temp->next = node;
        }
    }

    // Function to delete an element from the front of a doubly circular linked list
    void delbeg()
    {
        if (head == NULL)
        {
            cout << "The circular linked list is already empty" << endl;
            return;
        }
        else
        {
            if (head->next == head)
            {
                delete (head);
                head = NULL;
            }
            else
            {
                struct Node *del = head;
                struct Node *temp = head->prev;
                head = head->next;
                temp->next = head;
                head->prev = temp;
                delete (del);
            }
        }
    }

    // Function to delete an element from end of a doubly circular linked list
    void delend()
    {
        if (head == NULL)
        {
            cout << "The circular linked list is already empty" << endl;
            return;
        }
        else if (head->next == head)
        {
            delbeg();
        }
        else
        {
            struct Node *end;
            end = head->prev;
            end->prev->next = head;
            head->prev = end->prev;
            delete (end);
        }
    }

    //Function to delete a node of the doubly circular linked list with the given data
    void delmid(int value)
    {
        if (head==NULL)
        {
            cout<<"The list is already empty"<<endl;
        }
        else
        {
            struct Node* temp=head;
            while (temp->next!=head&&temp->data!=value)
            {
                temp=temp->next;
            }
            if (temp->data!=value)
            {
                cout<<"The entered value is not present in the linked"<<endl;
                return;
            }
            else if (temp->next==head)
            {
                delend();
            }
            else if (temp==head)
            {
                delbeg();
            }
            else
            {
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                delete(temp);
            }
        }
        
    }
    // Function to Print the Circular linked list
    void print()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != head)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
};

int main()
{
    CircularLLusingDoubleLL ll;
    ll.pushbeg(40);
    ll.pushbeg(30);
    ll.pushbeg(20);
    ll.pushbeg(10);
    ll.delmid(100);
    ll.print();
    return 0;
}
