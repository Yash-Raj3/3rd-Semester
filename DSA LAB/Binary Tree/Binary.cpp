#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
class Binary
{
public:
    Node *root;
    Binary()
    {
        root = NULL;
    }
};
Node *add(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->val)
    {
        root->left = add(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = add(root->right, val);
    }

    return root;
}
void travesal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    travesal(root->left);
    travesal(root->right);
}
int main()
{
    Binary b1;
    b1.root = add(b1.root, 1);
    b1.root = add(b1.root, 2);
    b1.root = add(b1.root, 5);
    b1.root = add(b1.root, 3);
    b1.root = add(b1.root, 6);
    travesal(b1.root);
}