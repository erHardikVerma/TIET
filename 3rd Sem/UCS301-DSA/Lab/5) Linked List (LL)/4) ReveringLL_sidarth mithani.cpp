//Linked list using Struct 
#include<iostream>
using namespace std;
struct Node
{
    public:
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head=NULL;
    }
    //Function to reverse the entered linked list
    Node* reverse(Node* node)
    {
        if(node==NULL)
            return NULL;
        if (node->next==NULL)
        {
            head=node;
            return node;
        }
        Node* node1= reverse(node->next);
        node1->next=node;
        node->next=NULL;
        return node;
    }

    //Function to print the linked list
    void print()
    {
        struct Node* temp=head;
        int count=0;
        while (temp!=NULL)
        {
            cout<<temp->data<<" "<<count<<endl;
            temp=temp->next;
        }
    }

    //Function to add an element to the linked list    
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    
};
int main()
{
    LinkedList ll;
    ll.push(50);
    ll.push(40);
    ll.push(30);
    ll.push(20);
    ll.push(10);
    ll.print();

    ll.reverse(ll.head);

    ll.print();
    return 0;
}
