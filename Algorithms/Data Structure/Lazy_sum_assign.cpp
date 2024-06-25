const int N = 100001; check
int a[N], tree[4 * N], lazy[4 * N];

check if int or long long

// int merge(int a, int b) { return a + b;}

// 0-based indexing
void build(int node, int tL, int tR) {
    if (tL == tR) {
        tree[node] = a[tL];
        return;
    }
    int mid = (tL + tR) / 2;

    build(2 * node, tL, mid);
    build(2 * node + 1, mid + 1, tR);

    tree[node] = merge(tree[2 * node] , tree[2 * node + 1]);
}
void propagate(int node, int tL, int tR) {
    check if -1 or 0
    if (lazy[node] == -1) return;
    tree[node] = (tR - tL + 1) * lazy[node];

    if (tL != tR) {
        lazy[2 * node] = lazy[node];
        lazy[2 * node + 1] = lazy[node];
    }
    lazy[node] = -1;   
}

void update(int node, int tL, int tR, int qL, int qR, int val) {
    propagate(node, tL, tR);
    if (tR < qL || tL > qR) {
        return;
    }
    if (tL >= qL && tR <= qR) {
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
        return identity; set identity
    }

    if (l <= tL && tR <= r) {
        return tree[node];
    }
    int mid = (tL + tR) / 2;

    int QL = query(2 * node, tL, mid, l, r);
    int QR = query(2 * node + 1, mid + 1, tR, l, r);

    return merge(QL, QR);
}
