#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    //Default constructor
    Node()
    {
        data=0;
        next=NULL;
    }
    //Parameterised Constructor
    Node(int data)
    {
        //this is used to point to the global variable
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList
{
    Node* head;
    //When Linked List Class is used using object then a global class variable head is created with the default value NULL
    public:
    LinkedList()
    {
        head=NULL;
    }
    void push(int);
    void print();
};
//Insertion at the begenning 
void LinkedList::push(int data)
{
    Node* new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    //or we can directly use the following
    // Node* new_node=new Node(data);

    new_node->next=head;
    head=new_node;
    
}

//Function to print all the elements of the linked list
void LinkedList::print()
{
    while (head!=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }    
}

int main()
{
    LinkedList listobj;
    listobj.push(10);
    listobj.push(20);
    listobj.push(30);
    listobj.push(40);
    listobj.print();
    return 0;
}
