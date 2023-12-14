#include <bits/stdc++.h>
using namespace std;

struct Point3D
{
    int x, y, z;
};

bool SoSanh(Point3D &a, Point3D &b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else if (a.y != b.y)
    {
        return a.y > b.y;
    }
    else
    {
        return a.z < b.z;
    }
}

int main()
{
    int n;
    cout << "Nhap so diem 3 chieu: ";
    cin >> n;
    vector<Point3D> points(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Tap diem thu " << i + 1 << " :" << endl;
        cout << "x = ";
        cin >> points[i].x;
        cout << "y = ";
        cin >> points[i].y;
        cout << "z = ";
        cin >> points[i].z;
    }
    sort(points.begin(), points.end(), SoSanh);
    cout << "Sap xep cac diem theo x tang dan, y giam dan, z tang dan: " << endl;
    for (const Point3D &p : points)
    {
        cout << p.x << " " << p.y << " " << p.z << endl;
    }
    return 0;
}
