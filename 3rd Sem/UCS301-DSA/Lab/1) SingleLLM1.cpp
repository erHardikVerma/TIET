#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
};

//To insert the node at the begenning
void push(Node **head_ref, int data)
{
    Node* new_node=new Node(data);
    new_node->next=*head_ref;
    *head_ref=new_node;
}

//To insert a node at the end of the linked list
void pushend(Node **head_ref,int data)
{
    Node* new_node=new Node(data);
    Node* endingofLL=*head_ref;
    if (*head_ref==NULL)
    {
        //Implies that the LL is empty
         *head_ref=new_node;
         return;
    }
    
    //The followig loop is used to find the last node of the LL
    while (endingofLL->next!=NULL)
    {
        endingofLL=endingofLL->next;
    }
   endingofLL->next=new_node; 
}

//Function to insert the new node after a given Node Number
void pushmid(Node **head_ref,int data,int pos)
{
    Node* new_node=new Node(data);
    Node* prev_node=*head_ref;
    int count=1;
    while (count!=pos)
    {
        if(prev_node->next==NULL)
        {
            cout<<"The position "<<pos<<" is out of the index of the LL:"<<endl;
            return;
        }
        else
        {
            prev_node=prev_node->next;
            count++;
        }
    }
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

//Function to delete an element from the begenning of the linked list
void delbeg(Node **head_ref)
{
    Node* temp=new Node();
    temp=*head_ref;
    *head_ref=temp->next;
    delete(temp);
}

//Function to delete a node from the end
void delend(Node **head_ref)
{
    if (head_ref==NULL)
    {
        cout<<"The linked list is empty "<<endl;
        return;
    }
    
    Node* endofLL=new Node();
    endofLL=*head_ref;
    while (endofLL->next->next!=NULL)
    {
        endofLL=endofLL->next;
    }
    delete(endofLL->next);
    endofLL->next=NULL;
}

//Function to delete element at a particular index
void delmid(Node** head_ref,int pos)
{
    if(head_ref==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    Node* temp=new Node();
    temp=*head_ref;
    int count=0;
    if (pos==0)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    while (count!=(pos-1))
    {
        if (temp->next->next==NULL)
        {
            cout<<"Invalid Input:"<<endl;
            return;
        }
        count++;
        temp=temp->next;
    }
    Node* next=temp->next->next;
    free(temp->next);
    temp->next=next;
}

//Function to print the linked list
void print(Node* node)
{
    while (node!=NULL)      
    {
        cout<<" "<<node->data<<endl;
        node=node->next;
    }
}

int main()
{
    //Call by reference
    // push(&head,10);
    // push(&head,20);
    // push(&head,30);
    // push(&head,40);
    // pushmid(&head,0,2);
    // pushmid(&head,0,1);
    // pushmid(&head,0,4);
    // pushmid(&head,0,2);
    // pushmid(&head,0,99);
    //Call by value
    Node* head=NULL;
    pushend(&head,10);
    pushend(&head,20);
    pushend(&head,30);
    pushend(&head,40);
    print(head);
    cout<<"\n"<<endl;
    delmid(&head,4);
    print(head);
    return 0;
}
