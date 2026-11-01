#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

// Create and Insert;
void Insert(Node *&root, int val)
{
    Node *newNode = new Node(val);
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *temp = queue[front++];

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            queue[rear++] = temp->right;
        }
    }
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(Node *root)
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
void update(Node *&root, int oldVal, int newVal)
{
    if (root == NULL)
    {
        return;
    }
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int found = 0;
    while (front < rear)
    {
        Node *temp = queue[front++];
        if (temp->data == oldVal)
        {
            temp->data = newVal;
            cout << "Value Changed!" << endl;
            found = 1;
            return;
        }
        if (temp->left != NULL)
        {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL)
        {
            queue[rear++] = temp->right;
        }
    }
    if (found == 0)
    {
        cout << "Value Not found!" << endl;
    }
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int cL = countNodes(root->left);
    int cR = countNodes(root->right);
    return cL + cR + 1;
}
void PrintKthLevel(Node *root, int K)
{
    if (root == NULL)
    {
        return;
    }
    if (K == 1)
    {
        cout << root->data << " ";
        return;
    }

    PrintKthLevel(root->left, K - 1);
    PrintKthLevel(root->right, K - 1);
}

static int idx = -1;
Node *insertByorder(int preOd[])
{
    idx++;
    if (preOd[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preOd[idx]);
    root->left = insertByorder(preOd);
    root->right = insertByorder(preOd);
    return root;
}
int search(int l, int r, int *in, int t)
{
    for (int i = l; i <= r; i++)
    {
        if (in[i] == t)
        {
            return i;
        }
    }
    return -1;
}
Node *FromPreAin(int *pre, int *in, int &preidx, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    Node *root = new Node(pre[preidx]);
    int idx = search(l, r, in, pre[preidx]);
    preidx++;

    root->left = FromPreAin(pre, in, preidx, l, idx - 1);
    root->right = FromPreAin(pre, in, preidx, idx + 1, r);
    return root;
}
int main()
{

    Node *root = NULL;
    Insert(root, 3);
    Insert(root, 5);
    Insert(root, 2);
    Insert(root, 1);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    cout << endl;
    levelorder(root);
    cout << endl;
    update(root, 2, 7);
    levelorder(root);
    cout << endl;
    cout << "Max Height: " << height(root) - 1;
    cout << endl;

    cout << "Total Nodes: " << countNodes(root) << endl;
    PrintKthLevel(root, 2);
    cout << endl;
    int preOd[15] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root2 = insertByorder(preOd);
    postorder(root2);
    cout << endl;
    int pre[10] = {3, 9, 20, 15, 7};
    int in[10] = {9, 3, 15, 20, 7};
    int preidx = 0;
    Node *root3 = FromPreAin(pre, in, preidx, 0, 4);
    inorder(root3);
}