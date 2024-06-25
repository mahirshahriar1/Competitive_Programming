#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int tree[4 * MAXN];

void update(int id, int l, int r, int k, int u) {
    if (l == r) {
        tree[id] += u;
        return;
    }
    int mid = (l + r) >> 1;

    if (k <= mid) update(2 * id, l, mid, k, u);

    else update(2 * id + 1, mid + 1, r, k, u);

    tree[id] = (tree[2 * id] + tree[2 * id + 1]);   
}

int query(int id, int l, int r, int k) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;

    if (k <= tree[2 * id]) return query(2 * id, l, mid, k);

    else return query(2 * id + 1, mid + 1, r, k - tree[2 * id]);
    
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        update(1, 1, MAXN, x, +1);
    }

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if (k > 0) {
            update(1, 1, MAXN, k, +1);
        }
        else {
            if (k < 0) k = -k;
            int x = query(1, 1, MAXN, k);          
            update(1, 1, MAXN, x, -1);
        }
    }

    cout << (tree[1] == 0 ? 0 : query(1, 1, MAXN, 1)) << "\n";
}