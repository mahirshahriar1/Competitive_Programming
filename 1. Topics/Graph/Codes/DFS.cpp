#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

vector <int> graph[ N ];
bool visited[ N ];


// void dfs(int node) {
//     visited[node] = true;
//     for (int i = 0; i < g[node].size(); i++) {
//         int child = g[node][i]; 
//         if (!visited[child]) {          
//             dfs(child);
//         }
//     }
// }

void dfs(int node) {
    cout << "\nnode: " << node << endl;
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        cout << "childs : " << child << " " << visited[child] << endl;
        if (!visited[child]) {
            cout << "called: " << child << endl;
            dfs(child);
        }
    }
    cout << "--> finished: " << node << '\n' << endl;
//    for (auto child: graph[node]) {
//        if (!visited[child]) {
//            dfs(child);
//        }
//    }
}

int main() {
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    // 6 9
    // 1 3 
    // 1 5 
    // 3 5
    // 3 4 
    // 3 6 
    // 3 2 
    // 2 6
    // 4 6
    // 5 6

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);

    // graph[1].push_back(2);
    // graph[2].push_back(1);

    // graph[1].push_back(3);
    // graph[3].push_back(1);

    // graph[2].push_back(4);
    // graph[4].push_back(2);

    // graph[3].push_back(5);
    // graph[5].push_back(3);

    // memset(visited, false, sizeof(visited));
    // dfs(1);

    return 0;
}
