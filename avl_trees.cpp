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

int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
    {
        return (lheight + 1);
    }
    else
    {
        return (rheight + 1);
    }
}

int blanceFactor(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return (height(root->left) - height(root->right));
}

struct node *rightRotate(struct node *root)
{
    struct node *x = root->left;
    struct node *t = x->right;

    x->right = root;
    t = root->left;
    return x;
}
struct node *leftRotate(struct node *root)
{
    struct node *x = root->right;
    struct node *t = x->left;

    x->left = root;
    t = root->right;
    return x;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        struct node *new_node = new node(key);
        root = new_node;
        return root;
    }
    if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        cout << "No duplicate values allowed!" << endl;
        return root;
    }

    int bf = blanceFactor(root);

    if (bf > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }
    else if (bf < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }
    else if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

struct node *deletenode(struct node *root, int val)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (val < root->data)
    {
        root->left = deletenode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletenode(root->right, val);
    }
    else
    {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
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

int main()
{
    struct node *root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(4);

    insert(root, 7);
    deletenode(root, 6);
    inorder(root);
}