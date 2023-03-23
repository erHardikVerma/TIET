#include<iostream>
using namespace std;
struct Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
struct DLL
{
    struct Node* head;
    DLL()
    {
        head=NULL;
    }
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

    void shuffle(int pos1,int pos2)
    {
        struct Node* end=head;
        int arr[100];
        int k;
        while (end!=NULL)
        {
            end=end->next;
        }
        struct Node* pos1pointer=head;
        int counter=1;
        while (counter!=pos1)
        {
            pos1pointer=pos1pointer->next;
        }
        struct Node* pos2pointer=head;
        counter=1;
        while (counter!=pos2)
        {
            pos2pointer=pos2pointer->next;
        }
        pos1pointer->prev->next=end;
        end->next=pos1pointer;
        pos2pointer->next=NULL;
        pushend(pos1pointer->data);
        print();
    }
    
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
};
int main()
{
    DLL ll;
    int flag=0;
    int number_of_inputs,x=1;
    cin>>number_of_inputs;
    for (int i = 0; i < number_of_inputs; i++)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            int a;
            cin>>a;
            if(flag==0)
            {
                ll.pushbeg(a);
                flag=1;
            }
            else
            {
                ll.pushend(a);
                flag=0;
            }
        }
        else if (ch=='S')
        {
            int a;
            int b;
            cin>>a;
            cin>>b;
            ll.shuffle(a,b);
        }
        else if (ch=='D')
        {
            ll.print();
        }
        
        
    }
    
    return 0;
}
