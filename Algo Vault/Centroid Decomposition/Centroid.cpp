//  Fixed-Length Paths I
// Given a tree of n nodes, your task is to count the number of distinct paths that consist of exactly k edges.
 
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int sz;
vector<int> graph[MAX];
bool isCentroid[MAX];
int cnt[200001]{1}; 
int mx_depth;
long long ans = 0;
int sub[MAX];
int n, k;

void calcSubTree(int s, int p) {
    sub[s] = 1;
    for (int x : graph[s]) {
        if (x == p or isCentroid[x]) continue;
        calcSubTree(x, s);
        sub[s] += sub[x];
    }
}

int getCentroid(int s, int p) {
    for (int x : graph[s]) {
        if (!isCentroid[x] && x != p && sub[x] > (sz / 2))
            return getCentroid(x, s);
    }
    return s;
}

void get_cnt(int node, int parent, bool flag, int depth = 1) {
    if (depth > k)  return;
    mx_depth = max(mx_depth, depth);

    if (flag) cnt[depth]++;
    else ans += cnt[k - depth];

    for (int i : graph[node]) {
        if (!isCentroid[i] && i != parent)
            get_cnt(i, node, flag, depth + 1);
	}
}

void decompose(int s, int p)
{
    calcSubTree(s, p);
    sz = sub[s];
    int c = getCentroid(s, p);
    isCentroid[c] = true;

    for (int x : graph[c]) {
        if (!isCentroid[x]) {
            get_cnt(x, c, 0);
			get_cnt(x, c, 1); 
		}
	}
    
    fill(cnt, cnt + mx_depth + 1, 0);
	cnt[0] = 1;
    mx_depth = 0;
    for (int i : graph[c]) {
        if (!isCentroid[i]) {
            decompose(i, c);
		}
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    decompose(1, 0);
    cout << ans << '\n';

    return 0;
}