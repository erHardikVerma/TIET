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
    Node()
    {
        data = 0;
        next = NULL;
    }
};
struct CircularLL
{
    struct Node *head;
    CircularLL()
    {
        head = NULL;
    }

    // Inserting an element at the begenning of the circular linked list

    void pushbeg(int data)
    {
        struct Node *node = new Node(data);
        if (head == NULL)
        {
            node->next = node;
        }
        else
        {
            node->next = head;
            struct Node *endnode = head;
            while (endnode->next != head)
            {
                endnode = endnode->next;
            }
            endnode->next = node;
        }
        head = node;
    }

    // Insertion at the end of the circular linked list

    void pushend(int data)
    {
        struct Node *node = new Node(data);
        struct Node *endnode = head;
        if (head == NULL)
        {
            node->next = node;
            head = node;
        }
        else
        {
            while (endnode->next != head)
            {
                endnode = endnode->next;
            }
            endnode->next = node;
            node->next = head;
        }
    }

    // Function to insert the node after a particular value in the linked list

    void pushmid(int data, int value)
    {
        struct Node *node = new Node(data);
        struct Node *temp = head;
        while (temp->next != head && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == head && temp->data != value)
        {
            cout << "The node is not present in the linked list" << endl;
        }
        else
        {
            node->next = temp->next;
            temp->next = node;
        }
    }

    // Function to delete an element from the begenning of the singly circular linked list
    void delfront()
    {
        if (head == NULL)
        {
            cout << "The cicrcular linked list is already empty" << endl;
        }
        else
        {
            struct Node *temp = head;
            struct Node *del = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            if (temp == head)
            {
                head = NULL;
            }
            else
            {
                temp->next = head->next;
                head = head->next;
            }
            delete (del);
        }
    }

    // Function to delete an elment from the end of the singly circular linked list
    void delend()
    {
        struct Node *temp = head;
        struct Node *del = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            del = temp->next;
            temp->next = head;
        }
        delete (del);
    }

    // Function to delete a node with a specific value
    void delmid(int value)
    {
        if (head == NULL)
        {
            cout << "The circular linked list is already empty" << endl;
        }
        else
        {
            struct Node *temp = head;
            struct Node *prev = temp;
            while (temp->next != head && temp->data != value)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp->data != value)
            {
                cout << "The value entered is not present in the linked list" << endl;
                return;
            }
            else if (temp == head)
            {
                delfront();
            }
            else if (temp->next == head)
            {
                delend();
            }
            else
            {
                prev->next = temp->next;
            }
            delete (temp);
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
    CircularLL ll;
    // ll.pushbeg(40);
    // ll.pushbeg(30);
    // ll.pushbeg(20);
    // ll.pushbeg(10);
    ll.pushend(10);
    ll.pushend(20);
    ll.pushend(30);
    ll.pushend(40);
    ll.delmid(1100);
    ll.print();
    return 0;
}
