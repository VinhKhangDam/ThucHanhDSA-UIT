#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[min], a[i]);
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
    int a[100], n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    cout << "Mang khi chua sap xep: ";
    XuatMang(a, n);
    SelectionSort(a, n);
    cout << "\nMang sau khi sap xep: ";
    XuatMang(a, n);
    return 0;
}