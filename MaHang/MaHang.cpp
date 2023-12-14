#include <bits/stdc++.h>
using namespace std;
#define Max 100
struct node
{
    int data;
    node *next;
};
typedef node *Hashtable[Max];

void InitHashTable(Hashtable &HT)
{
    for (int i = 0; i < Max; i++)
    {
        HT[i] = NULL;
    }
}

int Hash(int k)
{
    return k % Max;
}

void AddTail(node *&l, int data)
{
    node *temp = new node{data, NULL};
    if (l == NULL)
    {
        l = temp;
    }
    else
    {
        node *p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

bool CheckUnique(node *l, int itemCode)
{
    node *p = l;
    while (p != NULL)
    {
        if (p->data == itemCode)
        {
            return false;
        }
    }
    return true;
}

void Insert(Hashtable &HT, int data)
{
    int i = Hash(data);
    if (CheckUnique(HT[i], data))
    {
        AddTail(HT[i], data);
    }
}

int CountUniqueItems(Hashtable &HT)
{
    int count;
    for (int i = 0; i < Max; i++)
    {
        node *p = HT[i];
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
    }
    return count;
}

int main()
{
    Hashtable HT;
    InitHashTable(HT);

    int N;
    cout << "Nhap so luong hang: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int itemp;
        cout << "Ma hang: ";
        cin >> itemp;
        Insert(HT, itemp);
    }
    cout << "So loai hang khac nhau: " << CountUniqueItems(HT) << endl;
    return 0;
}