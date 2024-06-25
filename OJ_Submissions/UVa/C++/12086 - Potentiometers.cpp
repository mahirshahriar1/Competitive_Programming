#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <class T>
struct segment_tree
{
    int n;
    vector<T> stree;
    function<T(const T &, const T &)> merge;
    T identity = T();
    segment_tree(int n, function<T(const T &, const T &)> merge, T identity) : n(n), merge(merge), identity(identity)
    {
        stree.resize(4 * n + 5);
    }
    void build(const vector<T> &arr, int node, int b, int e)
    {
        if (b == e)
        {
            stree[node] = arr[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(arr, 2 * node, b, mid);
        build(arr, 2 * node + 1, mid + 1, e);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    segment_tree(const vector<T> &arr, function<T(const T &, const T &)> merge, T identity) : n(arr.size()), merge(merge), identity(identity)
    {
        stree.resize(4 * n + 5);
        build(arr, 1, 0, n - 1);
    }
    void set(int node, int b, int e, int ind, T val)
    {
        if (ind > e or ind < b)
            return;
        if (ind <= b and ind >= e)
        {
            stree[node] = val;
            return;
        }
        int mid = (b + e) >> 1;
        set(2 * node, b, mid, ind, val);
        set(2 * node + 1, mid + 1, e, ind, val);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    void set(int ind, T val) { set(1, 0, n - 1, ind, val); }

    void update(int node, int b, int e, int ind, T val)
    {
        if (ind > e or ind < b)
            return;
        if (ind <= b and ind >= e)
        {
            stree[node] = merge(stree[node], val);
            return;
        }
        int mid = (b + e) >> 1;
        update(2 * node, b, mid, ind, val);
        update(2 * node + 1, mid + 1, e, ind, val);
        stree[node] = merge(stree[2 * node], stree[2 * node + 1]);
    }
    void update(int ind, T val) { update(1, 0, n - 1, ind, val); }

    T query(int node, int b, int e, int l, int r)
    {
        if (l > e or r < b)
            return identity;
        if (l <= b and r >= e)
            return stree[node];
        int mid = (b + e) >> 1;
        T c1 = query(2 * node, b, mid, l, r);
        T c2 = query(2 * node + 1, mid + 1, e, l, r);
        return merge(c1, c2);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int tc;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    while (cin >> n, n != 0) {
        if (tc) cout << '\n';
        cout << "Case " << ++tc << ":\n";
        vector<int> v(n);
        for (auto &x: v) cin >> x;
        segment_tree<int> st(v, [](const int &a, const int &b) { return a + b; }, 0);
        string ss;
        while (cin >> ss) {
            if (ss == "END") break;
            int a, b;
            cin >> a >> b;
            if (ss == "M") {
                cout << st.query(a - 1, b - 1) << '\n';
            } else {
                st.set(a - 1, b);
            }
        }        
    }

    return 0;
}