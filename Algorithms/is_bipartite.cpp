bool is_bipartite(const vector<vector<int>> &adj, vector<int> &col, int u, int c = 0) {
    col[u] = c;
    for (int v : adj[u]) {
        if (col[v] == -1) {
            if (!is_bipartite(adj, col, v, c ^ 1))
                return false;
        } else if (col[v] == c) {
            return false;
        }
    }
    return true;
}

bool is_bipartite(vector<vector<int>>& adj, vector<int>& color, int s) {
    color[s] = 1;
    queue <int> q;
    q.push(s);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (auto v : adj[u]) {
            if (u == v) return false;
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
                continue;
            }
            if (color[v] == color[u]) return false;
        }
    }
 
    return true;
}
 