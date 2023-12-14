#include <bits/stdc++.h>
using namespace std;

void QuickSort(int a[], int left, int right)
{
    int i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            ;
            j--;
        }
    }
    if (left < j)
        QuickSort(a, left, j);
    if (right > i)
        QuickSort(a, i, right);
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
    int a[1001], n;
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
    QuickSort(a, 0, n - 1);
    cout << "\nMang khi da sap xep: ";
    XuatMang(a, n);
    return 0;
}