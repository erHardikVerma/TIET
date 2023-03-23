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

struct StacksUsingLinkedList
{
    struct Node *head;
    StacksUsingLinkedList()
    {
        head = NULL;
    }

    void push(int data)
    {
        struct Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            cout << "Popped: " << head->data << endl;
            head = NULL;
        }
        else
        {
            struct Node *del = head;
            cout << "Popped: " << head->data << endl;
            head = head->next;
            delete (del);
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "The stack is empty" << endl;
            return;
        }
        else
        {
            struct Node *temp = head;
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
    StacksUsingLinkedList st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    st.pop();
    st.pop();
    st.display();
    return 0;
}
