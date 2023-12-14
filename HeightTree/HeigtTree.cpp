#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *t, int x)
{
    if (t == NULL)
    {
        node *p = new node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    else
    {
        if (t->data > x)
        {
            t->left = insert(t->left, x);
        }
        else
        {
            t->right = insert(t->right, x);
        }
    }
    return t;
}

void AddNode(node *t, node *Node)
{
    if (t)
    {
        if (t->data == Node->data)
        {
            return;
        }
        else if (Node->data < t->data)
        {
            AddNode(t->left, Node);
        }
        else
            AddNode(t->right, Node);
    }
    else
    {
        t = Node;
    }
}

int HeightTree(node *t)
{
    if (t == NULL)
        return 0;
    return 1 + max(HeightTree(t->left), HeightTree(t->right));
}

int main()
{
    int n, x;
    node *t = NULL;
    cout << "Nhap so node: ";
    cin >> n;
    cout << "Nhap tung node vao: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        t = insert(t, x);
    }
    cout << "Do cao cua cay vua nhap la: " << HeightTree(t) - 1;
    return 0;
}