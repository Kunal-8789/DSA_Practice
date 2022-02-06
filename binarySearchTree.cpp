#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void insert(struct node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "Cannot insert" << key << endl;
            return;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *n = new node(key);
    if (key < prev->data)
    {
        prev->left = n;
    }
    else
    {
        prev->right = n;
    }
}
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    //Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
struct node *search(struct node *root, int key)
{
    if (root = NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
    void topview(struct node *root)
    {
        if (root == NULL)
    {
        return;
    }
     if (root->left == NULL)
    {
        while (root!= NULL)
        {
            cout << root->data << " ";
            root = root-> right;
        }
        
    }
    else if (root->right == NULL)
    {
        while (root!= NULL)
        {
            cout << root->data << " ";
            root = root-> left;
        }
        
    }
    
    }

int isBst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }  
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    struct node *root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(4);
    cout << (isBst(root) == 1 ? "It is binary search tree" : "It is not a binary search tree") << endl;
    // preorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // insert(root, 6);
    inorder(root);
    cout << endl;
    deleteNode(root, 3);
    inorder(root);
    cout << endl;
    return 0;
}
