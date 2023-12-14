#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
    {
        i++;
    }
    if (i == n)
        return 0;
    return 1;
}

int main()
{
    int a[1001], n, x;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int ketqua = LinearSearch(a, n, x);
    if (ketqua == 1)
        cout << "Tim thay gia tri";
    else
        cout << "Khong tim thay gia tri";
    return 0;
}