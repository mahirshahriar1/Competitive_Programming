#include <bits/stdc++.h>
using namespace std;

struct node
{
    int64_t lazy;
    int64_t curr;
    int64_t sum;
};
const int mx = 100005;
node tree[4 * mx];

void merge(int v) {
    tree[v].curr = tree[2 * v].curr + tree[2 * v + 1].curr;
    tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].curr = 100;
        tree[v].sum = tl * 100LL;
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge(v);
    }
}

void propagate(int v, int tl, int tr) {
    if(tree[v].lazy != 0) {
        tree[v].curr += (tr - tl + 1) * tree[v].lazy;
        tree[v].sum += (tl + tr) * 1LL *  (tr - tl + 1) / 2 * tree[v].lazy;
        if(tl != tr) {
            tree[2 * v].lazy += tree[v].lazy;
            tree[2 * v + 1].lazy += tree[v].lazy;
        }
        tree[v].lazy = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int64_t val) {
    propagate(v, tl, tr);

    if(tl > tr || tl > r || tr < l) {
        return;
    }

    if(tl >= l && tr <= r) {
        tree[v].lazy += val; // apply to lazy
        propagate(v, tl, tr);
        return;
    }

    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm + 1, tr, l, r, val);
    merge(v);
}

int64_t query(int v, int tl, int tr, int l, int r) {
    propagate(v, tl, tr);

    if(tl > tr || tl > r || tr < l) {
        return 0;
    }

    if(tl >= l && tr <= r) {
        return tree[v].sum - (l - 1) * tree[v].curr;
    }
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, r)
        + query(2 * v + 1, tm + 1, tr, l, r);
}

void run_case() {
    memset(tree, 0, sizeof(tree));

    int n, q;
    cin >> n >> q;

    build(1, 1, n);

    while(q--) {
        string s;
        int i, j, u;
        cin >> s;
        if(s == "change") {
            cin >> i >> j >> u;
            update(1, 1, n, i, j, u);
        } else {
            cin >> i >> j;
            cout << query(1, 1, n, i, j) << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        run_case();
    }
}