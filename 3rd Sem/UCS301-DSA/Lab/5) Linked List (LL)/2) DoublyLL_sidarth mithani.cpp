#include<iostream>
using namespace std;
struct Node
{
    public:
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
struct DoublyLL
{
    struct Node* head;
    DoublyLL()
    {
        head=NULL;
    }

    //Function to add an element to the begenning of the Doubly Linked List
    void pushbeg(int data)
    {
        struct Node* new_node=new Node(data);
        new_node->next=head;
        if(head!=NULL)
        {
            head->prev=new_node;
        }
        head=new_node;
    }

    //Function to add an element at the end of a doubly linked list
    void pushend(int data)
    {
        struct Node* new_node=new Node(data);
        struct Node* endofll=head;
        if (head==NULL)
        {
            head=new_node;
            return;
        }
        while (endofll->next!=NULL)
        {
            endofll=endofll->next;
        }
        endofll->next=new_node;
        new_node->prev=endofll;
        return;
    }

    //Function to add a new node at the given Index
    void pushmid(int data,int pos)
    {
        struct Node* prev_node=head;
        struct Node* new_node=new Node(data);
        int count=0;
        while (count!=(pos-1))      
        {
            if(prev_node->next==NULL&&pos>count)
            {
                cout<<"Invalid Index Entered: "<<endl;
                return;
            }
            
            prev_node=prev_node->next;
            count++;
        }
        if (++count==pos)
        {
            pushend(data);
            return;
        }
        new_node->next=prev_node->next;
        new_node->prev=prev_node;
        prev_node->next->prev=new_node;
        prev_node->next=new_node;

    }

    //Function to delete an element from the front of the linked list
    void delfront()
    {
        struct Node* del=head;
        if(head==NULL)
        {
            cout<<"The Linked List is already empty"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            head=NULL;
            delete(del);
            return;
        }
        del->next->prev=NULL;
        head=del->next;
        free(del);
    }

    //Function to delete a node from the end of the linked list
    void delend()
    {
        struct Node* last=head;
        if(head==NULL)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            head=NULL;
            delete(last);
            return;
        }

        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->prev->next=NULL;
        delete(last);      
    }

    //Function to delete an element at a particular index
    void delmid(int i)
    {
        int count=0;
        struct Node* del=head;
        if(head==NULL)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            head=NULL;
            delete(del);
            return;
        }


        while (count!=i)
        {   
            if(del->next==NULL)
            {
                cout<<"Invalid index entered:"<<endl;
                return;
            }            
            del=del->next;
            count++;
        }
        del->prev->next=del->next;
        del->next->prev=del->prev;
        delete(del);
    }

    //Function to reverse the entire doubly linked list
    void rev()
    {
        struct Node* current=head;
        while (current!=NULL)
        {
            if (current->next==NULL)    
            {
                head=current;
            }
            
            struct Node* temp=current->next;
            struct Node* next=current->next;
            struct Node* prev=current->prev;

            current->next=prev;
            current->prev=next;

            current=temp;
        }
        
    }
    //Function to print the doubly linked list
    void print()
    {
        struct Node* temp=head;
        if(temp==NULL)
        {
            cout<<"List is empty: "<<endl;
            return;
        }
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
    }

    void printrev()
    {
        struct Node* endofll=head;
        while (endofll->next!=NULL)
        {
            endofll=endofll->next;
        }
        while (endofll!=NULL)
        {
            cout<<endofll->data<<" ";
            endofll=endofll->prev;
        }
   
    }
};
int main()
{
    DoublyLL ll ;
    ll.pushend(10);
    ll.pushend(20);
    ll.pushend(30);
    ll.pushend(40);
    ll.print();
    cout<<"\n"<<endl;
    ll.rev();
    ll.print();
    return 0;
}



    // ll.printrev();
