#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		//Node* top;
};
class stack
{	
	public:
		Node* top;
		stack()
		{
			top=NULL;
		}
		void push(int x)
		{
			Node *nnode=new Node();
			nnode->data=x;
			if(top==NULL)
			{
				top=nnode;
				nnode->next=NULL;
			}
			else
			{
				nnode->next=top;
				top=nnode;
			}
		}
		void pop()
		{
			if(top==NULL)
			{
				cout<<"Underflow";
			}
			else
			{
				Node* nnode=top;
				cout<<"deleted element "<<nnode->data<<endl;
				top=nnode->next;
				delete nnode;
			}
		}
		void display()
		{
			Node* temp=top;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main()
{
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.display();
	st.pop();
	st.display();
}
