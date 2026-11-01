#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;

    Node(int v)
    {
        left = right = NULL;
        data = v;
    }
};
void inorderC(Node *root, int *&arr, int &i)
{
    if (root == NULL)
    {
        return;
    }
    inorderC(root->left, arr, i);
    arr[i++] = root->data;
    inorderC(root->right, arr, i);
}

Node *insert(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *BST(int arr[], int l, int r)
{
    if (l > r)
    {
        return NULL;
    }

    int mid = l + (r - l) / 2;
    Node *newNode = new Node(arr[mid]);
    newNode->left = BST(arr, l, mid - 1);
    newNode->right = BST(arr, mid + 1, r);

    return newNode;
}
int count(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}
Node *merge(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return NULL;
    }
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }
    int n1 = count(root1);
    int n2 = count(root2);
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    int a = 0, b = 0;
    inorderC(root1, arr1, a);
    inorderC(root2, arr2, b);
    int temp[100];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            temp[k++] = arr1[i++];
        }
        else
        {
            temp[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        temp[k++] = arr1[i++];
    }
    while (j < n2)
    {
        temp[k++] = arr2[j++];
    }

    return BST(temp, 0, k - 1);
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
int main()
{
    int arr[] = {3, 1, 5, 6, 7};
    int arr1[] = {4, 8, 9, 11, 2};
    Node *root1 = NULL, *root2 = NULL;
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        root1 = insert(root1, arr[i]);
        root2 = insert(root2, arr1[i]);
    }
    Node *root3 = merge(root1, root2);

    inorder(root1);
    cout << endl;
    inorder(root2);
    cout << endl;
    inorder(root3);
}