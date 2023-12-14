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
            return;
        else if (Node->data < t->data)
            AddNode(t->left, Node);
        else
            AddNode(t->right, Node);
    }
    else
    {
        t = Node;
    }
}

node *DeleteNode(node *t, int k)
{
    if (t == NULL)
    {
        return t;
    }
    if (t->data > k)
    {
        t->left = DeleteNode(t->left, k);
        return t;
    }
    else if (t->data < k)
    {
        t->right = DeleteNode(t->right, k);
        return t;
    }
    if (t->left == NULL)
    {
        node *temp = t->right;
        delete t;
        return temp;
    }
    else if (t->right == NULL)
    {
        node *temp = t->left;
        delete t;
        return temp;
    }
    else
    {
        node *parent = t;
        node *succ = t->right;
        while (t->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        if (parent != t)
        {
            parent->left = succ->right;
        }
        else
            parent->right = succ->right;

        t->data = succ->data;
        delete succ;
        return t;
    }
}

node *TimPhanTu(node *t, int x)
{
    if (t)
    {
        if (t->data == x)
            return t;
        else if (t->data > x)
            return TimPhanTu(t->left, x);
        return TimPhanTu(t->right, x);
    }
    return NULL;
}

void NLR(node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void LRN(node *t)
{
    if (t != NULL)
    {
        LRN(t->left);
        LRN(t->right);
        cout << t->data << " ";
    }
}

void LNR(node *t)
{
    if (t != NULL)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}

void printTree(node *t)
{
    if (t != NULL)
    {
        printTree(t->left);
        cout << t->data << " ";
        printTree(t->right);
    }
}

int main()
{
    int n, x;
    node *t = NULL;
    cout << "Nhap so node cua cay: ";
    cin >> n;
    cout << "Nhap tung node vao cay: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        t = insert(t, x);
    }
    cout << "\nCay sau khi them toan bo node vao la: ";
    printTree(t);
    int d;
    cout << "\nNhap phan tu muon them vao cay: ";
    cin >> d;
    t = insert(t, d);
    cout << "\nCay sau khi them phan tu " << d << " vao la: ";
    printTree(t);
    int a;
    cout << "\nNhap vao phan tu muon xoa: ";
    cin >> a;
    t = DeleteNode(t, a);
    cout << "\nCay sau khi xoa phan tu " << a << " la: ";
    printTree(t);
    cout << "\nNhap phan tu muon tim kiem trong cay: ";
    int b;
    cin >> b;
    node *z = TimPhanTu(t, b);
    if (z == NULL)
        cout << "\nKhong tim thay phan tu: ";
    else
        cout << "\nTim thay phan tu: ";
    cout << "\nDuyet cay theo NLR la: ";
    NLR(t);
    cout << "\nDuyet cay theo LRN la: ";
    LRN(t);
    cout << "\nDuyet cay theo LNR la: ";
    LNR(t);
    return 0;
}
