// directed graph cycle detection
void dfsCycleFinder(string u, bool &drunk) {
    if (drunk) return;
    colors[u] = 1;
    for (string v : child[u]) {
        if (colors[v] == 0) {
            dfsCycleFinder(v, drunk);
        } else if (colors[v] == 1) {
            cylcle = true;
            return;
        }
    }
    colors[u] = 2;
}

bool bfsCycleFinder() {
    map<string, int> in_degree;
    queue<string> q;

    // Calculate in-degrees
    for (auto& p : child) {
        for (auto& node : p.second) {
            in_degree[node]++;
        }
    }

    // Initialize queue with nodes having 0 in-degree
    for (auto& p : colors) {
        if (in_degree[p.first] == 0) {
            q.push(p.first);
        }
    }

    int processed_count = 0;

    while (!q.empty()) {
        string node = q.front();
        q.pop();
        processed_count++;

        for (auto& neighbor : child[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If processed_count is not equal to the number of unique nodes, there's a cycle
    return processed_count != colors.size();
}

// Undirected graph cycle detection
bool dfsCycleFinder(string u, string parent) {
    colors[u] = 1;
    for (string v : child[u]) {
        if (colors[v] == 0) {
            if (dfsCycleFinder(v, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool bfsCycleFinder() {
    queue<string> q;
    map<string, string> parent;

    for (auto& p : colors) {
        if (p.second == 0) {
            q.push(p.first);
            parent[p.first] = p.first;
        }
    }

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        for (string v : child[u]) {
            if (colors[v] == 0) {
                colors[v] = 1;
                parent[v] = u;
                q.push(v);
            } else if (v != parent[u]) {
                return true;
            }
        }
    }

    return false;
}