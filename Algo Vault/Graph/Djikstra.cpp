vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int djikstra() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({edges[0][0], {0, 0}});
    dist[0][0] = edges[0][0];
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        int w = cur.first;
        if (dist[x][y] < w) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && dist[nx][ny] > dist[x][y] + edges[nx][ny]) {
                dist[nx][ny] = dist[x][y] + edges[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }
    return dist[row - 1][col - 1];
}