#include<iostream>
using namespace std;
struct node *insert(struct node *,int);
struct node *CreateNewNode(int);
void display(struct node *);
//bool search(struct node *,int);
struct node * insuccesor(node *);
struct node * inpredecessor(node *);
struct node *deletebst(node *,int);
//struct node *deletenode(struct node *,int);
struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;
//struct node *root=NULL;

int main()
{
	struct node *succ_ptr,*pred_ptr;
	int number;
	//root=NULL;
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,60);

	root=insert(root,55);
	root=insert(root,52);
	root=insert(root,70);
	deletebst(root,50);
//	root=insert(root,30);
//	root=insert(root,45);
//	root=insert(root,47);
	display(root);
//	cout<<"After deletion inorder BST is:---"<<endl;
//	root=deletenode(root,60);
//	display(root);
//	
//	cout<<"enter the number to be searched ";
//	cin>>number;
//	if(search(root,number)==true)
//	{
//		cout<<"item found";
//	}
//	else
//	{
//		cout<<"item not found";
//	}
// find_pre_succ(root,&pre,&suc,40)
// succ_ptr=insuccesor(root);
// cout<<endl<<"Successor is:=="<<succ_ptr->data;
// pred_ptr=inpredecessor(root);
// cout<<endl<<"predecessor is:=="<<pred_ptr->data;
	return 0;
}
struct node * insuccesor(node *root)
{
	node *p=root->right;
	while(p->left)
	{
		p=p->left;
	}
	return p;
}
struct node * inpredecessor(node *root)
{
	node *p=root->left;
	while(p->right)
	{
		p=p->right;
	}
	return p;
}
struct node *Findmin(struct node *root)
{
	struct node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
	
}
struct node *deletebst(node *root,int data)
{
	if(root==NULL)
	return root;
	else if(data<root->data)
	root->left=deletebst(root->left,data);
	else if(data>root->data)
	root->right=deletebst(root->right,data);
	else
	{
		// CASE 1
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
		root=NULL;
		return root;
		}
		// CASE 2
		else if(root->left==NULL)
		{
			struct node *temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct node *temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else
		{
//			struct node *temp=insuccessor(root);
//			swap(root->data,temp->data);
//			root->right=deletebst(root->right,data);
			struct node *temp=Findmin(root->right);
			root->data=temp->data;
			root->right=deletebst(root->right,temp->data);
		}
	}
}
void find_pre_succ(node *root,node *&pre,node *&suc,int key)
{
	if(!root)
	{
		return;
	}
	if(root->data==key)
	{
		if(root->left)
		{
			pre=inpredecessor(root);
		}
		if(root->right)
		{
			suc=insuccesor(root);
		}
	}
	if(key>root->data)
	{
		pre=root;
		find_pre_succ(root->right,pre,suc,key);
		
	}
	else if(key<root->data)
	{
		suc=root;
		find_pre_succ(root->left,pre,suc,key);
	}
}

node *CreateNewNode(int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
node *insert(node *root,int data)
{
	if (root==NULL)
	{
		root=CreateNewNode(data);
		return root;
		
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void display(struct node *root)
{
	if(root==NULL)
	{
		return;}
		else
		{
	display(root->left);
	cout<<root->data;
	display(root->right);	
	}		
}
//struct node *deletenode(struct node *root,int data)
//{
////	int data=data;
//	if(root==NULL)
//	return NULL;
//	else if(data<root->data)
//	{
//	root->left=	deletenode(root->left,data);
//	 } 
//	 else if(data>root->data)
//	 {
//	 	root->right=deletenode(root->right,data);
//	 }
//	 else
//	 {
//	 	if(root->left==NULL && root->right==NULL)
//	 	{
//	 		delete root;
//	 		root=NULL;
//	 		return root;
//		 }
//		 else if(root->left==NULL)
//		 {
//		 	struct node *temp=root;
//		 	root=root->right;
//		 	delete temp;
//		 	return root;
//		 }
//		 else if(root->right==NULL)
//		 {
//		 	struct node *temp=root;
//		 	root=root->left;
//		 	delete temp;
//		 	return root;
//		 }
//		 else
//		 {
////		 	struct node *temp=Findmin(root->right);
////		 	root->data=temp->data;
////		 	root->right=delete(root->right,temp->data);
////		 	return root;
//		 }
//	 }
//	 
//}
////bool search(struct node *root,int data)
//{
//	//cout<<root->data;
//	if (root==NULL)
//	{
//		//cout<<"not found";
//		return 0;//"false";
//	}
//	else if(data==root->data)
//	{
//		return 1;//"true";
//	}
//	else if(data<=root->data)
//	{
//		return search(root->left,data);
//	}
//	else
//	{
//		return search(root->right,data);
//	}
//}

//void find_pre_succ(node *root,node *&pre,node *&suc,int key)
//{
//	if(!root)
//	{
//		return;
//	}
//	if(root->data==key)
//	{
//		//Check if left exist or not
//		if(root->left)
//		{
//			pre=inpredecessor(root);
//		}
//		//check if right exist or not
//		if(root->right)
//		{
//			suc=insuccesor(root);
//		}
//	}
//	if(key>root->data)
//	{
//		pre=root;
//		find_pre_succ(root->right,pre,suc,key);
//		
//	}
//	else if(key<root->data)
//	{
//		suc=root;
//		find_pre_succ(root->left,pre,suc,key); 
//	}
//}
