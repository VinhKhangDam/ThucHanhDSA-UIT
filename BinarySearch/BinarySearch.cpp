#include <bits/stdc++.h>
using namespace std;

void InterchanceSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

bool BinarySearch(int a[], int &n, int &x)
{
    int left = 0, right = n - 1;
    int mid;
    do
    {
        mid = (right + left) / 2;
        if (a[mid] == x)
            return true;
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    } while (left <= right);
    return false;
}

int main()
{
    int a[1000], n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "\na[" << i << "]= ";
        cin >> a[i];
    }
    cout << "Mang khi chua sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    InterchanceSort(a, n);
    cout << "\nMang khi da sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nNhap vao phan tu can tim: ";
    cin >> x;
    bool result = BinarySearch(a, n, x);
    if (result == true)
        cout << "Tim thay gia tri can tim trong mang";
    else
        cout << "Khong tim thay gia tri can tim!";
    return 0;
}