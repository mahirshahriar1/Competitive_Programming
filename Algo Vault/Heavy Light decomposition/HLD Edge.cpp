// SPOJ - QTREE 
// Change i ti - change the cost of the i-th edge to ti
// Query u v - find the maximum edge cost on the path from u to v

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct HeavyLightDecomposition
{
    static const int N = 1e5 + 5;
    static const int inf = 1e9 + 5;
    static const int lgN = 20;
    typedef pair<int, int> pii;

    int n, Node;
    int otherEnd[N];
    int A[N], sub[N], par[N], depth[N], EdgeId[N];
    int chainNo, chainInd[N], chainHead[N], posInTree[N];
    vector<pii> graph[N];
    vector<int> Edge[N];
    int tree[2 * N];

    int neutral;
    function<int(int, int)> operation;

    void initialize(int _n, function<int(int, int)> _operation, int _neutral)
    {
        n = _n;
        operation = _operation;
        neutral = _neutral;
        memset(tree, 0, sizeof(tree));
        chainNo = 0, Node = 1;
        for (int i = 0; i < N; i++) {
            graph[i].clear();
            Edge[i].clear();
            A[i] = 0, sub[i] = 0, depth[i] = 0, EdgeId[i] = 0;
            chainInd[i] = 0, chainHead[i] = -1, posInTree[i] = 0;
        }
    }

    void AddEdge(int u, int v, int w)
    {
        graph[u].push_back({v, w}), graph[v].push_back({u, w});
    }

    void dfs(int s, int p)
    {
        par[s] = p, sub[s] = 1, depth[s] = depth[p] + 1;
        for (int i = 0; i < graph[s].size(); i++)
        {
            pii k = graph[s][i];
            int v = k.first, w = k.second;
            if (v != p)
            {
                EdgeId[Edge[s][i]] = graph[s][i].first;
                dfs(v, s);
                sub[s] += sub[v];
            }
        }
    }

    void HLD(int s, int p, int cost)
    {
        if (chainHead[chainNo] == -1) chainHead[chainNo] = s;
        chainInd[s] = chainNo;
        posInTree[s] = Node;
        A[Node++] = cost;
        int mxChild = -1, ncost;
        for (int i = 0; i < graph[s].size(); i++) {
            pii k = graph[s][i];
            int v = k.first, w = k.second;
            if (v != p) {
                if (mxChild == -1 || sub[mxChild] < sub[v]) {
                    mxChild = v;
                    ncost = w;
                }
            }
        }
        if (mxChild != -1) HLD(mxChild, s, ncost);

        for (int i = 0; i < graph[s].size(); i++) {
            pii k = graph[s][i];
            int v = k.first, w = k.second;
            if (v != p && v != mxChild) {
                chainNo++;
                HLD(v, s, w);
            }
        }
    }

    int LCA(int u, int v)
    {
        while (1) {
            int pu = chainHead[chainInd[u]], pv = chainHead[chainInd[v]];
            if (pu == pv) return (depth[u] < depth[v] ? u : v);
            if (depth[pu] < depth[pv]) v = par[pv];
            else u = par[pu];
        }
    }

    void Build()
    {
        for (int i = 1; i < Node; ++i) tree[n + i] = A[i];
        for (int i = n - 1; i > 0; --i) tree[i] = operation(tree[i << 1], tree[i << 1 | 1]);
    }

    int Query(int l, int r)
    {
        int res = neutral;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = operation(res, tree[l++]);
            if (r & 1) res = operation(res, tree[--r]);
        }
        return res;
    }

    void Update(int pos, int nval)
    {
        for (tree[pos += n] = nval; pos > 1; pos >>= 1)
            tree[pos >> 1] = operation(tree[pos], tree[pos ^ 1]);
    }

    int QueryUP(int u, int v)
    {
        if (u == v) return 0;
        int uchain, vchain = chainInd[v];
        int ans = -inf;
        while (1) {
            uchain = chainInd[u];
            if (uchain == vchain) {
                int st = posInTree[v], en = posInTree[u];
                int ret = Query(st + 1, en + 1);
                ans = max(ans, ret);
                break;
            }
            int st = posInTree[chainHead[uchain]], en = posInTree[u];
            int ret = Query(st, en + 1);
            ans = max(ans, ret);
            u = chainHead[uchain], u = par[u];
        }
        return ans;
    }
    
    void UpdateHLD(int pos, int v)
    {
        pos = EdgeId[pos];
        Update(posInTree[pos], v);
    }

    int QueryHLD(int u, int v)
    {
        int lca = LCA(u, v);
        int x = QueryUP(u, lca), y = QueryUP(v, lca);
        return max(x, y);
    }

} hld;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        hld.initialize(n, [](int a, int b) { return max(a, b); }, 0);

        for (int i = 1; i <= n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            hld.AddEdge(u, v, w);
            hld.Edge[u].push_back(i);
            hld.Edge[v].push_back(i);
        }

        hld.dfs(1, 0);
        hld.HLD(1, 0, -1);
        hld.Build();

        string s;
        while (1)
        {
            cin >> s;
            if (s == "DONE") break;

            else if (s == "QUERY") {
                int l, r;
                cin >> l >> r;
                cout << hld.QueryHLD(l, r) << "\n";
            }
            else {
                int no, val;
                cin >> no >> val;
                hld.UpdateHLD(no, val);
            }
        }
    }
    return 0;
}
