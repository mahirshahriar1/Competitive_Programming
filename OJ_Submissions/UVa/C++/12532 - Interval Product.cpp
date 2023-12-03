#include <bits/stdc++.h>
using namespace std;

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


int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, k, i, x, y;   
 
    while(cin >> n >> k) {       
        vector<int> v(n, 0);
        segment_tree<int> st(n, [](int v, int b) { return v * b; }, 1);

        for(i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] = (v[i] > 0) - (v[i] < 0);
        }
        // for (auto &x : v) cout << x << " "; cout << "\n";
        st.build(v, 1, 0, n - 1);      

        string s;
        while(k--) {
            cin >> s >> x >> y;
            
            if(s == "C") {
                y = (y > 0) - (y < 0);
                st.set(--x, y);
            } else {
                int res = st.query(--x, --y);                 
                if ( res == 1 ) cout << "+";
                else if ( res == -1 ) cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
    }

    return 0;
}