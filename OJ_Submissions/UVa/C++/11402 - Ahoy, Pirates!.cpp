#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

const int N = 1024000 + 5; 
int tree[4 * N], lazy[4 * N];
string s;
int x;

int merge(int a, int b) { return a + b;}

void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = s[tL] - '0';
        return;
    }
    int mid = (tL + tR) / 2;

    build(2 * node, tL, mid);
    build(2 * node + 1, mid + 1, tR);

    tree[node] = merge(tree[2 * node] , tree[2 * node + 1]);
}


void propagate(int node, int tL, int tR) {
    int x = lazy[node];    
    if (x == -1) return;
    lazy[node] = -1;

    if (x == 2) tree[node] = (tR - tL + 1) - tree[node];
    else if (x == 1) tree[node] = (tR - tL + 1);
    else tree[node] = 0;
    
    if (tL == tR) return;
    if (x == 2) {
       int left = 2 * node, right = 2 * node + 1;

       if (lazy[left] == 2) lazy[left] = -1;
       else  lazy[left] = abs(lazy[left] ^ 1);

       if (lazy[right] == 2) lazy[right] = -1;
       else   lazy[right] = abs(lazy[right] ^ 1);
       // lazy[2 * node] ^= 1; makes 1 to 0 and 0 to 1 and -1 to -2 and abs(-2) = 2
    } else {        
        lazy[2 * node] = x;
        lazy[2 * node + 1] = x;
    }
}

void update(int node, int tL, int tR, int qL, int qR, int val) {
    propagate(node, tL, tR);
    if (tR < qL || tL > qR) {
        return; 
    }
    if (qL <= tL && tR <= qR) {
        lazy[node] = val;
        propagate(node, tL, tR);
        return;
    }

    int mid = (tL + tR) / 2;

    update(2 * node, tL, mid, qL, qR, val);
    update(2 * node + 1, mid + 1, tR, qL, qR, val);

    tree[node] = merge(tree[2 * node] , tree[2 * node + 1]);
}

int query(int node, int tL, int tR, int l, int r) {
    propagate(node, tL, tR);
    
    if (tR < l || tL > r) {
        return 0; 
    }

    if (l <= tL && tR <= r) {
        return tree[node];
    }
    int mid = (tL + tR) / 2;

    int QL = query(2 * node, tL, mid, l, r);
    int QR = query(2 * node + 1, mid + 1, tR, l, r);

    return merge(QL, QR);
}


void solve(int tc) 
{
    cout << "Case " << tc << ":" << endl;
    int n;
    cin >> n;   
    string t;
    s = '0';
    for (int j = 1; j <= n; ++j) {
        int x;
        cin >> x >> t;
        while (x--) s += t;
    }
    n = s.size();
   
    for (int i = 0; i < 4 * (n + 5); ++i) {
        tree[i] = 0;
        lazy[i] = -1;
    }
    build(1, 1, n);
       
    int q;
    cin >> q;
    int tt = 0;
    while (q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'F') update(1, 1, n, a + 1, b + 1, 1);
        else if (c == 'E') update(1, 1, n, a + 1, b + 1, 0);
        else if (c == 'I') update(1, 1, n, a + 1, b + 1, 2);
        else cout << "Q" << ++tt << ": " << query(1, 1, n, a + 1, b + 1) << endl;
    }
    s.clear();
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        solve(tc);        
    }

    return 0;
}