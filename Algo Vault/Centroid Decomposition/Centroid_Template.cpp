//  Fixed-Length Paths I
// Given a tree of n nodes, your task is to count the number of distinct paths that consist of exactly k edges.
 
#include <bits/stdc++.h>
using namespace std;

struct centroid
{
    vector<vector<int>> edges;
    vector<bool> vis;
    vector<int> par;
    vector<int> sz;
    int n;

    void init(int s)
    {
        n = s;        
        edges = vector<vector<int>>(n, vector<int>());
        vis = vector<bool>(n, 0);
        par = vector<int>(n);
        sz = vector<int>(n);
    }

    void edge(int a, int b)
    {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int find_size(int v, int p = -1)
    {
        if (vis[v]) return 0;
        sz[v] = 1;

        for (int x : edges[v])
        {
            if (x != p)
            {
                sz[v] += find_size(x, v);
            }
        }

        return sz[v];
    }

    int find_centroid(int v, int p, int n)
    {
        for (int x : edges[v])
        {
            if (x != p)
            {
                if (!vis[x] && sz[x] > n / 2)
                {
                    return find_centroid(x, v, n);
                }
            }
        }

        return v;
    }

    void init_centroid(int v = 0, int p = -1)
    {
        find_size(v);
        int c = find_centroid(v, -1, sz[v]);
        vis[c] = true;
        par[c] = p;

        for (int x : edges[c])
        {
            if (!vis[x])
            {
                init_centroid(x, c);
            }
        }
    }
} tree;

int cnt[200001]{1}, mx_depth, sz, k, n;
int64_t ans;

void get_cnt(int node, int parent, bool flag, int depth = 1) {
    if (depth > k)  return;
    mx_depth = max(mx_depth, depth);

    if (flag) cnt[depth]++;
    else ans += cnt[k - depth];

    for (int i : tree.edges[node]) {
        if (!tree.vis[i] && i != parent)
            get_cnt(i, node, flag, depth + 1);
	}
}

void decompose(int s, int p)
{
    sz = tree.find_size(s);   
    int c = tree.find_centroid(s, -1, sz);
    tree.vis[c] = true;

    for (int x : tree.edges[c]) {
        if (!tree.vis[x]) {
            get_cnt(x, c, 0);
			get_cnt(x, c, 1); 
		}
	}
    
    fill(cnt, cnt + mx_depth + 1, 0);
	cnt[0] = 1;
    mx_depth = 0;
    for (int i : tree.edges[c]) {
        if (!tree.vis[i]) {
            decompose(i, c);
		}
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n >> k;

    tree.init(n);

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        --u, --v;
        tree.edge(u, v);
    }    
    decompose(0, -1);
    cout << ans << '\n';

    return 0;
}