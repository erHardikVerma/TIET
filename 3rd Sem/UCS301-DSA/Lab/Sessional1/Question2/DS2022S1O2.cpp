#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};


void top(Node** head, int data)
{
	Node* t= new Node();
	t->data = data;
	t->next = (*head);
	t->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = t;
	(*head) = t;
}


void append(Node** head, int data)
{
	Node* nnode = new Node();

	Node* last = *head; 
	nnode->data = data;
	nnode->next = NULL;
	
	if (*head == NULL) {
		nnode->prev = NULL;
		*head = nnode;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = nnode;
	nnode->prev = last;
	

	return;
}


void print(Node* node)
{
	
	while (node != NULL) {
		cout << " " << node->data << " ";
		
		node = node->next;
	}

}


int main()
{
    int n,x=1;
    cin>>n;
    Node* head = NULL;
    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        if (ch=='I')
        {
            int a;
            cin>>a;
            if (x%2==0)
            {
                append(&head,a);
            }
            else
            {
                top(&head,a);
            }
        }
        else if (ch=='D')
        {
            print(head);
        }
        x++;
        
    }
	return 0;
}
