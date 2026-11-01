#include <iostream>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};
Node *Insert(Node *root, int val)
{
    Node *newNode = new Node(val);

    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = Insert(root->left, val);
    }
    else
    {
        root->right = Insert(root->right, val);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    queue[rear++] = NULL;
    while (front < rear)
    {
        Node *temp = queue[front++];
        if (temp == NULL)
        {
            if (front != rear)
            {
                cout << endl;
                queue[rear++] = NULL;
                continue;
            }
            else
            {
                break;
            }
        }
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL)
        {
            queue[rear++] = temp->right;
        }
    }
}
Node *inorderS(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteN(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = deleteN(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteN(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *IS = inorderS(root->right);
            root->data = IS->data;
            root->right = deleteN(root->right, IS->data);
        }
    }
    return root;
}
int BinarySearch(Node *root, int t, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == t)
    {
        return level;
    }
    if (t < root->data)
    {
        return BinarySearch(root->left, t, level + 1);
    }
    if (t > root->data)
    {
        return BinarySearch(root->right, t, level + 1);
    }
}
bool isValid(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    return isValid(root->left, min, root) && isValid(root->right, root, max);
}
int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}
int leaf(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return leaf(root->left) + leaf(root->right);
}
int Internal(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return 1 + Internal(root->left) + Internal(root->right);
}
int max(Node *root)
{

    if (root == NULL)
    {
        return -1;
    }
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int min(Node *root)
{

    if (root == NULL)
    {
        return -1;
    }
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int main()
{
    int arr[] = {3, 1, 5, 4, 6, 2};
    Node *root = NULL;

    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        root = Insert(root, arr[i]);
    }
    inorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;

    int level = BinarySearch(root, 1, 1);
    if (level == -1)
    {
        cout << "Element is not in Tree!" << endl;
    }
    else
    {
        cout << "Element is at Level: " << level << endl;
    }

    deleteN(root, 5);

    inorder(root);
    cout << endl;
    if (isValid(root, NULL, NULL))
    {
        cout << "Valid Binary search Tree!" << endl;
    }
    else
    {
        cout << "Invalid Binary Search tree!" << endl;
    }

    cout << "Sum of BST: " << sum(root) << endl;
    levelOrder(root);
    cout << endl;
    cout << "Number of Leaves: " << leaf(root) << endl;
    cout << "Internal Nodes: " << Internal(root) << endl;
    cout << "Maximun of Nodes: " << max(root) << endl;
    cout << "Minimum: " << min(root) << endl;
}
