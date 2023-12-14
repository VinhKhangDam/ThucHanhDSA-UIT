#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    bool operator<(const Point &a)
    {
        if (x == a.x)
            return y > a.y;
        return x < a.x;
    }
};

int main()
{
    int n;
    cout << "Nhap so diem: ";
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    for (const Point &p : points)
    {
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}
