#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
    //Constructor to create a new node
    Node(int data)
    {
        this->data = data;
        rchild = lchild = NULL;
    }
};

Node *create(int data)
{
    Node *newnode = new Node(data);
    return newnode;
}

// Insertion of a new node to the BST
Node *insert(int data, Node *root)
{
    if (root == NULL)
    {
        return create(data);
    }
    if (data < root->data)
    {
        root->lchild = insert(data, root->lchild);
    }
    else
    {
        root->rchild = insert(data, root->rchild);
    }
    return root;
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

// Preorder Traversal
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->lchild);
    preorder(root->rchild);
}

// Postorder Traversal
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " ";
}

// Recursive Searching
bool search(int key, Node *root)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root != NULL && root->data == key)
    {
        return true;
    }
    else
    {
        if (key < root->data)
        {
            search(key, root->lchild);
        }
        else
        {
            search(key, root->rchild);
        }
    }
}

// Iterative Search
bool itsearch(int key, Node *root)
{
    bool flag = false;
    while (root != NULL)
    {
        if (root->data == key)
        {
            flag = true;
            break;
        }
        else
        {
            if (key < root->data)
                root = root->lchild;
            else
                root = root->rchild;
        }
    }
    return flag;
}

// Findind the minimum element
Node *minimum(Node *root)
{
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}

// Findind the maximum element
Node *maximum(Node *root)
{
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root;
}

// Successor and Predecessor
void SuccPree(int key, Node *root, Node *&succ, Node *&pre)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        // Prdecessor
        if (root->lchild != NULL)
        {
            Node *temp = root->lchild;
            pre = maximum(temp);
        }
        // Successor
        if (root->rchild != NULL)
        {
            Node *temp = root->rchild;
            succ = minimum(temp);
        }
        return;
    }
    if (key < root->data)
    {
        succ = root;
        SuccPree(key, root->lchild, succ, pre);
    }
    else
    {
        pre = root;
        SuccPree(key, root->rchild, succ, pre);
    }
}

// Deletion of a Node from the the Binary Search Tree
Node *nodedelete(Node *root, int key)
{
    // Base Case of the recusion
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->lchild = nodedelete(root->lchild, key);
    }
    else if (key > root->data)
    {
        root->rchild = nodedelete(root->rchild, key);
    }
    else
    {
        //Case 1 if the node to be deleted had no childrens
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return NULL;
        }
        //Case 2 if the node to be deleted had 1 child
        else if (root->lchild == NULL)
        {
            Node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            Node *temp = root->lchild;
            free(root);
            return temp;
        }
        // Case 3 if the node to be deleted has 2 children
        Node *temp = minimum(root->rchild);
        root->data = temp->data;
        root->rchild = nodedelete(root->rchild, temp->data);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(41, root);
    root = insert(16, root);
    root = insert(53, root);
    root = insert(25, root);
    root = insert(46, root);
    root = insert(55, root);
    root = insert(42, root);

    inorder(root);
    cout << endl;

    root = nodedelete(root, 41);
    inorder(root);
    cout << endl;

    return 0;

    // Node *pre = NULL;
    // Node *succ = NULL;
    // SuccPree(55, root, succ, pre);
    // if (pre != NULL)
    //     cout << "Precessor is: " << pre->data << endl;
    // else
    //     cout << "No Precessor" << endl;

    // if (succ != NULL)
    //     cout << "Successor is: " << succ->data << endl;
    // else
    //     cout << "No Successor" << endl;

    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;

    //  search(41, root) ? cout << "Search Successful" << endl : cout << "Search Unsccessful" << endl;
    // itsearch(11, root) ? cout << "Search Successful" << endl : cout << "Search Unsccessful" << endl;

    // cout << "The minimum element is: " << minimum(root)->data << endl;
    // cout << "The maximum element is: " << maximum(root)->data << endl;
}
