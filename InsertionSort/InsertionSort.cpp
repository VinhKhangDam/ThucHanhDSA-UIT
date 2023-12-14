#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n)
{
    int pos, i;
    int x; // Lưu giá trị a[i] để tránh bị ghi đè khi dời phần tử
    for (i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n, a[1001];
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
    cout << "Mang khi chua sap xep: ";
    XuatMang(a, n);
    InsertionSort(a, n);
    cout << "\nMang khi da sap xep: ";
    XuatMang(a, n);
    return 0;
}