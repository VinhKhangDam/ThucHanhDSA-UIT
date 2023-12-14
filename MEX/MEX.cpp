#include <bits/stdc++.h>
using namespace std;

int mex(vector<int> a)
{
    int n = a.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s.find(i) == s.end())
        {
            return i;
        }
    }
    return n + 1;
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    vector<int> a(n);
    cout << "Nhap mang: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    int mex_value = mex(a);
    cout << "So tu nhien nho nhat chua xuat hien trong mang la (Mex): " << mex_value;
    return 0;
}