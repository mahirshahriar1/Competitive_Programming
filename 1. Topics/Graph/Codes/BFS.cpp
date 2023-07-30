#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector <int> graph[ N ];
int dist[ N ]; 
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int di[]={1,-1,0,0,1,1,-1,-1};
const int dj[]={0,0,1,-1,1,-1,1,-1};

void bfs(int source) {
    memset(dist, -1, sizeof(dist));
    queue <int> q;
    dist[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++) {
            int child = graph[f][i];
            if (dist[child] == -1) {
                dist[child] = dist[f] + 1;
                q.push(child);
            }
        }
    }
    //for (int i = 1; i <= 5; i++) cout << dist[i] << endl;
}

void cleargraph(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
}

int main() {
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[3].push_back(5);
    graph[5].push_back(3);

    bfs(1);
    return 0;
}
