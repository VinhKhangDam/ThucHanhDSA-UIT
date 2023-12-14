#include <bits/stdc++.h>
using namespace std;
#define Max 100

struct node
{
    string username, password;
    node *next;
};
typedef node *Hashtable[Max];

void InitHashTable(Hashtable &ht)
{
    for (int i = 0; i < Max; i++)
    {
        ht[i] = NULL;
    }
}

int Hash(string k)
{
    int sum = 0;
    for (char ch : k)
    {
        sum += ch;
    }
    return sum % Max;
}

void AddTail(node *&l, string username, string password)
{
    node *temp = new node{username, password, NULL};
    if (l == NULL)
    {
        l = temp;
    }
    else
    {
        node *p = l;
        while (p != NULL && p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void Insert(Hashtable &ht, string username, string password)
{
    int i = Hash(username);
    AddTail(ht[i], username, password);
}

string FindPass(Hashtable &ht, string username)
{
    int i = Hash(username);
    node *p = ht[i];
    while (p != NULL)
    {
        if (p->username == username)
        {
            return p->password;
        }
        p = p->next;
    }
    return "Chua dang ky!";
}

int main()
{
    int N, Q;
    Hashtable ht;
    InitHashTable(ht);
    cout << "Nhap so tai khoan ban dau: ";
    cin >> N;
    cout << "Nhap tung tai khoan : " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Tai khoan thu " << i + 1 << " :";
        string username, password;
        cout << "Tai khoan: ";
        cin >> username;
        cout << "Mat khau: ";
        cin >> password;
        Insert(ht, username, password);
    }
    cout << "Nhap so tai khoan can truy xet: ";
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string username;
        cout << "\nNhap tai khoan truy xet thu " << i + 1 << " :";
        cin >> username;
        string result = FindPass(ht, username);
        cout << result;
    }
    return 0;
}