#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

int dfs(int node, vector<int> &graph, vector<int> &sum, vector<int> &vis) {
	vis[node] = 1;
	int curr = 0;
	if (!vis[graph[node]] ) {		
		curr = 1 + dfs(graph[node], graph, sum, vis);
	}
	vis[node] = 0;	
	return sum[node] = curr;
}

void solve(const int &tc) {
	cout << "Case " << tc << ": ";
	int n;
	cin >> n;
	vector<int> graph(n, -1), sum(n, - 1), vis(n, 0);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		graph[x] = y;
	}
	int len = 0, res = 0;

	for (int i = 0; i < n; ++i) {
		if (sum[i] == -1) {
			dfs(i, graph, sum, vis);
		}
		if (sum[i] > len) {
			len = sum[i];
			res = i;
		}
	}

	cout << res + 1 << endl;
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