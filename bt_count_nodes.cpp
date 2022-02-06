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

int countnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countnodes(root->left) + countnodes(root->right) + 1;
}

int countleafnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countleafnodes(root->left) + countleafnodes(root->right);
    }
}

int countnonleafnodes(node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        return countnonleafnodes(root->left) + countnonleafnodes(root->right) + 1;
    }
}

int maxDepth(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);
    if (lDepth > rDepth)
    {
        return lDepth;
    }
    else
    {
        return rDepth;
    }
}

int identicalTrees(node *root, node *root1)
{
    if (root == NULL && root1 == NULL)
        return 1;
    if (root != NULL && root1 != NULL)
    {
        return (
            root->data == root1->data &&
            identicalTrees(root->left, root1->left) &&
            identicalTrees(root->right, root1->right));
    }
    return 0;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);

    int x = countnodes(root);
    int y = countleafnodes(root);
    cout << countnodes(root)<<endl;
    cout << countleafnodes(root)<<endl;
    cout << countnonleafnodes(root)<<endl;
    cout << maxDepth(root)<<endl;
    if (x = (2 * y - 1))
    {
        cout << "strict binary tree" << endl;
    }
    else
    {
        cout << "non-strict binary tree" << endl;
    }
    cout<<(identicalTrees(root,root1)==1?"identical trees":"not identical trees")<<endl;
    return 0;
}
