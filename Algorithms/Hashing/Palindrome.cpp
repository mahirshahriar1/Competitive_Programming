#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

struct Node{
    ll fwd, bwd, len;
};
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll B = 31;
ll p[N];
void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = (p[i - 1] * B) % mod;
    }

}

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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<Node> v(n);
    for (int i = 0; i < n; ++i) {
        char ch; cin >> ch;
        v[i].fwd = v[i].bwd = (int)ch;
        v[i].len = 1;
    }

    segment_tree<Node> st(v, [](Node a, Node b) {
        Node c;
        c.len = a.len + b.len;
        c.fwd = (a.fwd * p[b.len] + b.fwd) % mod;
        c.bwd = (b.bwd * p[a.len] + a.bwd) % mod;
        return c;
    }, Node());

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos; char ch;
            cin >> pos >> ch;
            st.set(pos - 1, Node{ch, ch, 1});
        } else {
            int l, r;
            cin >> l >> r;
            Node ans = st.query(l - 1, r - 1);
            if (ans.fwd == ans.bwd) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
 
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    init();
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        solve();
    }

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

struct Node{
    ll fwd, bwd, len;
};
const int MX_N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll B = 31;
ll p[MX_N];
void init() {
    p[0] = 1;
    for (int i = 1; i < MX_N; i++) {
        p[i] = (p[i - 1] * B) % mod;
    }

}

Node a[MX_N], tree[4 * MX_N];

Node merge(Node a, Node b) {
    Node c;
    c.len = a.len + b.len;
    c.fwd = (a.fwd * p[b.len] + b.fwd) % mod;
    c.bwd = (b.bwd * p[a.len] + a.bwd) % mod;
    
    return c;
}

void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = a[tL];
        return;
    }
    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(left, tL, mid);
    build(right, mid + 1, tR);
    tree[node] = merge(tree[left], tree[right]);
}

void update(int node, int tL, int tR, int i, Node v) {
    if (tL >= i && tR <= i) {
        tree[node] = v;
        return;
    }
    if (tR < i || tL > i) return;

    int mid = (tL + tR) / 2;
    int left = 2 * node, right = 2 * node + 1;
    update(left, tL, mid, i, v);
    update(right, mid + 1, tR, i, v);
    tree[node] = merge(tree[left], tree[right]);
}

Node query(int node, int tL, int tR, int qL, int qR) {
    if (tL >= qL && tR <= qR) {
        return tree[node];
    }
    if (tR < qL || tL > qR) {
        return Node{0, 0, 0};
    }
    int mid = (tL + tR) / 2;
    Node QL = query(2 * node, tL, mid, qL, qR);
    Node QR = query(2 * node + 1, mid + 1, tR, qL, qR);
    return merge(QL, QR);
}

void solve()
{
    int n, q;
    cin >> n >> q;
   
    for (int i = 0; i < n; ++i) {
        char ch; cin >> ch;
        a[i].fwd = a[i].bwd = (int)ch;
        a[i].len = 1;
    }
    build(1, 0, n - 1);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos; char ch;
            cin >> pos >> ch;            
            update(1, 0, n - 1, pos - 1, Node{ch, ch, 1});
        } else {
            int l, r;
            cin >> l >> r;
            Node ans = query(1, 0, n - 1, l - 1, r - 1);

            if (ans.fwd == ans.bwd) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
 
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    init();
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        solve();
    }

    return 0;
}

*/