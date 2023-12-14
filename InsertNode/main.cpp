#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

typedef struct node Node;

struct List
{
    node *head;
    node *tail;
};

typedef struct List LIST;

void KhoiTao(List &ds)
{
    ds.head = NULL;
    ds.tail = NULL;
}

node *TaoNode(int data)
{
    node *p = new node;
    if (p == NULL)
    {
        cout << "Khong du bo nho!";
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    return p;
}

void addTail(List &ds, node *p)
{
    if (ds.head == NULL)
    {
        ds.head = p;
        ds.tail = p;
    }
    else
    {
        ds.tail->next = p;
        ds.tail = p;
    }
}

void NhapCuoi(List &ds, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        cout << "Node thu " << i + 1 << " :";
        cout << "Nhap gia tri: ";
        cin >> data;
        node *p = TaoNode(data);
        addTail(ds, p);
    }
}

void XuatNode(node *p)
{
    cout << p->data << " ";
}

void Xuat(List &ds)
{
    node *p = ds.head;
    while (p != NULL)
    {
        XuatNode(p);
        p = p->next;
    }
}

void SortNode(List &ds)
{
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        for (node *p = k->next; p != NULL; p = p->next)
        {
            if (k->data > p->data)
            {
                swap(k->data, p->data);
            }
        }
    }
}

int main()
{
    int n;
    List ds;
    KhoiTao(ds);
    cout << "Nhap so node: ";
    cin >> n;
    NhapCuoi(ds, n);
    SortNode(ds);
    cout << "Danh sach khi chua them 1 phan tu: ";
    Xuat(ds);
    NhapCuoi(ds, 1);
    SortNode(ds);
    cout << "Danh sach sau khi them phan tu: ";
    Xuat(ds);
    return 0;
}