// CSES Path Queries II
// Find the maximum value on the path between two nodes in a tree.
// Update the value of a node.

#include <bits/stdc++.h>
using namespace std;

struct HEAVYLIGHT_DECOMPOSITION {
    static const int MAXN = 2e5 + 5;
    static const int INF = 1e9 + 5;

    int n, Node;
    int cost[MAXN];
    int A[MAXN], sub[MAXN], par[MAXN], depth[MAXN];
    int chainNo, chainInd[MAXN], chainHead[MAXN], posInTree[MAXN];
    vector<int> graph[MAXN];
    int tree[4 * MAXN];

    function<int(int, int)> operation;
    int neutral;

    void Initialize(int _n, function<int(int, int)> _operation, int _neutral) {
        n = _n;
        operation = _operation;
        neutral = _neutral;
        memset(tree, 0, sizeof(tree));
        chainNo = 0, Node = 1;
        for (int i = 0; i < MAXN; i++) {
            graph[i].clear();
            A[i] = 0, sub[i] = 0, cost[i] = 0;
            chainInd[i] = 0, chainHead[i] = -1, posInTree[i] = 0;
        }
    }

    void AddEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int s, int p) {
        par[s] = p, sub[s] = 1, depth[s] = depth[p] + 1;
        for (int v : graph[s]) {
            if (v != p) {
                dfs(v, s);
                sub[s] += sub[v];
            }
        }
    }

    void HLD(int s, int p) {
        if (chainHead[chainNo] == -1)
            chainHead[chainNo] = s;
        chainInd[s] = chainNo;
        posInTree[s] = Node;
        A[Node++] = cost[s];
        int mxChild = -1;
        for (int v : graph[s]) {
            if (v != p) {
                if (mxChild == -1 || sub[mxChild] < sub[v]) {
                    mxChild = v;
                }
            }
        }
        if (mxChild != -1)
            HLD(mxChild, s);
        for (int v : graph[s]) {
            if (v != p && v != mxChild) {
                chainNo++;
                HLD(v, s);
            }
        }
    }

    int LCA(int u, int v) {
        while (1) {
            int pu = chainHead[chainInd[u]], pv = chainHead[chainInd[v]];
            if (pu == pv)
                return (depth[u] < depth[v] ? u : v);
            if (depth[pu] < depth[pv])
                v = par[pv];
            else
                u = par[pu];
        }
    }

    void Build() {
        for (int i = 1; i < Node; ++i)
            tree[n + i] = A[i];

        for (int i = n - 1; i > 0; --i)
            tree[i] = operation(tree[i << 1], tree[i << 1 | 1]);
    }

    void Update(int pos, int nval) {
        for (tree[pos += n] = nval; pos > 1; pos >>= 1)
            tree[pos >> 1] = operation(tree[pos], tree[pos ^ 1]);
    }

    void UpdateHLD(int u, int nval) {
        Update(posInTree[u], nval);
    }

    int Query(int l, int r) {
        int res = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = operation(res, tree[l++]);
            if (r & 1)
                res = operation(res, tree[--r]);
        }
        return res;
    }

    int QueryUP(int u, int v) {
        if (u == v)
            return Query(posInTree[u], posInTree[u] + 1);
        int uchain, vchain = chainInd[v];
        int ans = neutral;
        while (1) {
            uchain = chainInd[u];
            if (uchain == vchain) {
                int st = posInTree[v], en = posInTree[u];
                int ret = Query(st, en + 1);
                ans = operation(ans, ret);
                break;
            }
            int st = posInTree[chainHead[uchain]], en = posInTree[u];
            int ret = Query(st, en + 1);
            ans = operation(ans, ret);
            u = chainHead[uchain], u = par[u];
        }
        return ans;
    }

    int QueryHLD(int u, int v) {
        int lca = LCA(u, v);
        return operation(QueryUP(u, lca), QueryUP(v, lca));
    }    

} hld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    hld.Initialize(n, [](int a, int b) { return max(a, b); }, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> hld.cost[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        hld.AddEdge(u, v);
    }

    hld.dfs(1, 0);
    hld.HLD(1, 0);
    hld.Build();

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            hld.cost[s] = x;
            hld.UpdateHLD(s, x);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << hld.QueryHLD(a, b) << " ";
        }
    }

    return 0;
}
