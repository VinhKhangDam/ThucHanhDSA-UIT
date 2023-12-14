#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct node
{
    string username, password;
    vector<string> passwordHistory;
    node *next;
};

typedef node *Hashtable[MAX];

void InitHashTable(Hashtable &HT)
{
    for (int i = 0; i < MAX; i++)
    {
        HT[i] = NULL;
    }
}

int Hash(string k)
{
    int sum = 0;
    for (char ch : k)
    {
        sum += ch;
    }
    return sum % MAX;
}

void AddTail(node *&l, string username, string password)
{
    node *temp = new node{username, password, {}, NULL};
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

void Insert(Hashtable &HT, string username, string password)
{
    int i = Hash(username);
    AddTail(HT[i], username, password);
    HT[i]->passwordHistory.push_back(password);
}

void PrintPasswordHistory(const vector<string> &passwordHistory)
{
    for (const string &password : passwordHistory)
    {
        cout << password << endl;
    }
}

string SearchPass(Hashtable &HT, string username)
{
    int i = Hash(username);
    node *p = HT[i];
    while (p != NULL)
    {
        if (p->username == username)
        {
            PrintPasswordHistory(p->passwordHistory);
            return " ";
        }
        p = p->next;
    }
    return "Chua dang ky!";
}

int main()
{
    Hashtable HT;
    InitHashTable(HT);

    int N, Q;
    cout << "Nhap so tai khoan ban dau: ";
    cin >> N;
    cout << "Nhap tung tai khoan: ";
    for (int i = 0; i < N; ++i)
    {
        cout << "Tai khoan thu " << i + 1 << " :";
        string username, password;
        cout << "Tai khoan la: ";
        cin >> username;
        cout << "Mat khau la: ";
        cin >> password;
        Insert(HT, username, password);
    }
    cout << "Nhap so tai khoan can truy xet: ";
    cin >> Q;
    cout << "NHap tung tai khoan can truy xet: ";
    for (int i = 0; i < Q; ++i)
    {
        string username;
        cout << "Nhap tai khoan truy xet: ";
        cin >> username;
        string result = SearchPass(HT, username);
        cout << result;
    }
}