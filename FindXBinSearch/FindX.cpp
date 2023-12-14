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

bool BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    int mid;
    do
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return true;
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    } while (left <= right);
    return false;
}

int main()
{
    int a[1000], N, x, Q;
    cout << "Nhap so luong mang: ";
    cin >> N;
    cout << "Nhap mang: ";
    for (int i = 0; i < N; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    InterchanceSort(a, N);
    cout << "Nhap so luong cau hoi truy van: ";
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cout << "Truy van thu " << i + 1 << ": ";
        cin >> x;
        bool result = BinarySearch(a, N, x);
        if (result == true)
            cout << "\nYES";
        else
            cout << "\nNO";
    }
    return 0;
}