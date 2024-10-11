// https://lightoj.com/problem/guarding-bananas

#include <bits/stdc++.h>
using namespace std;

/**
 Convex Hull ( graham scan )
 returns the points.
 change data type accordingly
 comp is also inside the point struct(same)
 points are Clock Wise Sorted
 for counter clock wise sorting chage last 2 lines -> up down vice versa & return down
**/

struct point
{
    int64_t x, y;
    point() {}
    point(int64_t x, int64_t y) : x(x), y(y) {}
    void operator=(const point &p) { x = p.x, y = p.y; }
    bool operator<(const point &p) { return x == p.x ? y < p.y : x < p.x; }
    point operator+(point p) { return point(x + p.x, y + p.y); }
    point operator-(point p) { return point(x - p.x, y - p.y); }
    point operator*(int64_t k) { return point(x * k, y * k); }
    point operator/(int64_t k) { return point(x / k, y / k); }
    int64_t cross(const point &p) const { return x * p.y - y * p.x; }
    int64_t dot(const point &p) const { return x * p.x + y * p.y; }
    int64_t dist(point q) { return ((x - q.x) * (x - q.x) + (y - q.y) * (y - q.y)); }
};

bool comp(point &p1, point &p2) { return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; }

bool cw(point &a, point &b, point &c)
{
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) < 0;
}
bool ccw(point &a, point &b, point &c)
{
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) > 0;
}
vector<point> convex_hull(vector<point> &v)
{
    if (v.size() == 1)
        return v;
    sort(v.begin(), v.end());
    point p1 = v[0], p2 = v.back();
    vector<point> up, down;
    up.push_back(p1), down.push_back(p1);
    for (int i = 1; i < v.size(); i++)
    {
        if (i == v.size() - 1 || cw(p1, v[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if (i == v.size() - 1 || ccw(p1, v[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    for (int i = down.size() - 2; i > 0; i--) {
        up.push_back(down[i]);
        // down.push_back(up[i]);
    }
    return up;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        cout << "Case " << tc << ": ";
        int n;
        cin >> n;
        vector<point> v(n);
        for (auto &[x, y] : v) cin >> x >> y;
        vector<point> hull = convex_hull(v);

        if (hull.size() < 3)
        {
            cout << "0\n";
            continue;
        }

        // for (auto &p : hull) cout << p.x << " " << p.y << '\n';

        // find min angle
        // angle = acos( dot(a,b) / (|a|*|b|) )
        
        double ans = 2000;        
        int len = hull.size();
        for (int i = 0; i < len; ++i)
        {
            int j = (i + 1) % len;
            int k = (i - 1 + len) % len;
            point v1 = hull[j] - hull[i];
            point v2 = hull[k] - hull[i];
            double dot_product = v1.dot(v2);
            double mag_v1 = sqrt(v1.dot(v1));
            double mag_v2 = sqrt(v2.dot(v2));
            double angle = acos(dot_product / (mag_v1 * mag_v2));
            ans = min(ans, angle * 180 / acos(-1));
        }
        cout << fixed << setprecision(8) << ans  << '\n';
    }

    return 0;
}