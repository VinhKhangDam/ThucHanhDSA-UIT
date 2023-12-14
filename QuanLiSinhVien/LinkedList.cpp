#include <bits/stdc++.h>
using namespace std;

struct node
{
    string MSSV;
    string Ten;
    double DTB;
    node *next;
};

typedef struct node Node;

struct List
{
    node *head;
    node *tail;
};

typedef struct List LIST;

void Khoitao(List &ds)
{
    ds.head = NULL;
    ds.tail = NULL;
}

int KiemTraRong(List ds)
{
    if (ds.head == NULL)
        return 0;
    return 1;
}

node *TaoNode(string MSSV, string Ten, double DTB)
{
    node *p = new node;
    if (p == NULL)
    {
        cout << "Khong du bo nho!";
        return NULL;
    }
    p->MSSV = MSSV;
    p->Ten = Ten;
    p->DTB = DTB;
    p->next = NULL;
    return p;
}

void addHead(List &ds, node *p)
{
    if (ds.head == NULL)
    {
        ds.head = p;
        ds.tail = p;
    }
    else
    {
        p->next = ds.head;
        ds.head = p;
    }
}

void NhapDau(List &ds, int n)
{
    string mssv, ten;
    double dtb;
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << " :" << endl;
        cin.ignore();
        cout << "Nhap ma so sinh vien: ";
        getline(cin, mssv);
        cout << "Nhap ho va ten sinh vien: ";
        getline(cin, ten);
        cout << "Nhap diem trung binh cua sinh vien: ";
        cin >> dtb;
        node *p = TaoNode(mssv, ten, dtb);
        addHead(ds, p);
    }
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
    string mssv, ten;
    double dtb;
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i + 1 << " :" << endl;
        cin.ignore();
        cout << "Nhap ma so sinh vien: ";
        getline(cin, mssv);
        cout << "Nhap ho va ten sinh vien: ";
        getline(cin, ten);
        cout << "Nhap diem trung binh cua sinh vien: ";
        cin >> dtb;
        node *p = new node;
        p = TaoNode(mssv, ten, dtb);
        addTail(ds, p);
    }
}

void XuatNode(node *p)
{
    cout << "Ma so sinh vien: " << p->MSSV << endl;
    cout << "Ho va ten sinh vien: " << p->Ten << endl;
    cout << "Diem trung binh cua sinh vien: " << p->DTB << endl;
}

void Xuat(List ds)
{
    node *p = ds.head;
    while (p != NULL)
    {
        XuatNode(p);
        p = p->next;
    }
}

node *FindSinhVien(List &ds, string x)
{
    node *p = ds.head;
    while (p != NULL && p->MSSV != x)
        p = p->next;
    return p;
}

void XoaDau(List &ds)
{
    node *p = ds.head;
    ds.head = ds.head->next;
    p->next = NULL;
    delete p;
}

void XoaCuoi(List &ds)
{
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        if (k->next == ds.tail)
        {
            delete ds.tail;
            k->next = NULL;
            ds.tail = k;
        }
    }
}

void XoaPhanTu(List &ds, string mssv)
{
    node *p = new node;
    if (ds.head->MSSV == mssv)
    {
        XoaDau(ds);
        return;
    }
    if (ds.tail->MSSV == mssv)
    {
        XoaCuoi(ds);
        return;
    }
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        if (k->MSSV == mssv)
        {
            p->next = k->next;
            delete k;
            return;
        }
        p = k;
    }
}

node *SinhVienCoDTBHon5(List &ds)
{
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        if (k->DTB >= 5)
        {
            XuatNode(k);
            cout << endl;
        }
    }
}

void XepLoai(List &ds)
{
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        if (k->DTB <= 3.6)
        {
            XuatNode(k);
            cout << "-Loai yeu" << endl;
        }
        else if (k->DTB >= 5 && k->DTB < 6.5)
        {
            XuatNode(k);
            cout << "-Loai trung binh" << endl;
        }
        else if (k->DTB >= 6.5 && k->DTB < 7)
        {
            XuatNode(k);
            cout << "-Loai trung binh kha" << endl;
        }
        else if (k->DTB >= 7 && k->DTB < 8)
        {
            XuatNode(k);
            cout << "-Loai kha" << endl;
        }
        else if (k->DTB >= 8 && k->DTB < 9)
        {
            XuatNode(k);
            cout << "-Loai gioi" << endl;
        }
        else
        {
            XuatNode(k);
            cout << "-Loai xuat sac" << endl;
        }
    }
}

void SapXep(List &ds)
{
    for (node *k = ds.head; k != NULL; k = k->next)
    {
        for (node *p = k->next; p != NULL; p = p->next)
        {
            if (k->DTB > p->DTB)
            {
                swap(k->DTB, p->DTB);
            }
        }
    }
    Xuat(ds);
}

int main()
{
    system("cls");
    List ds;
    Khoitao(ds);
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    NhapCuoi(ds, n);
    cout << "Du lieu sinh vien trong danh sach: " << endl;
    Xuat(ds);
    cout << "----------------------------------------------" << endl;
    cout << "Nhap so sinh vien can them vao dau: ";
    int b;
    cin >> b;
    NhapDau(ds, b);
    cout << "Danh sach sinh vien sau khi them " << b << " sinh vien vao dau: " << endl;
    Xuat(ds);
    cout << "----------------------------------------------" << endl;
    string x;
    cout << "Nhap ma so sinh vien can tim trong danh sach: ";
    cin.ignore();
    getline(cin, x);
    node *p = FindSinhVien(ds, x);
    if (p == NULL)
        cout << "Khong tim thay sinh vien!" << endl;
    else
        cout << "Sinh vien can tim co trong danh sach!" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Danh sach cac sinh vien co diem trung binh lon hon 5: ";
    SinhVienCoDTBHon5(ds);
    cout << "----------------------------------------------" << endl;
    cout << "Xep loai tung sinh vien: ";
    XepLoai(ds);
    cout << "----------------------------------------------" << endl;
    cout << "Danh sach sau khi sap xep tang dan theo diem trung binh: ";
    Xuat(ds);
    cout << "----------------------------------------------" << endl;
    string xoasinhvien;
    cin.ignore();
    cout << "Nhap mssv can xoa: ";
    getline(cin, xoasinhvien);
    XoaPhanTu(ds, xoasinhvien);
    cout << "Danh sach sau khi xoa sinh vien co ma so sinh vien " << xoasinhvien << " la: ";
    Xuat(ds);
    return 0;
}