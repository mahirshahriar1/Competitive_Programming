/*
    ADDED A Parent array to backtrack
    --762 - We Ship Cheap (uva)
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector <int> graph[ N ];
int dist[ N ]; 
int par[ N ];

void bfs(int source) {
    memset(dist, -1, sizeof(dist));
    memset(par, -1, sizeof(par));
    queue <int> q;
    dist[source] = 0;
    q.push(source);
    par[source]=-1;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int i = 0; i < graph[f].size(); i++) {
            int child = graph[f][i];
            if (dist[child] == -1) {
                dist[child] = dist[f] + 1;
                par[child]=f;
                q.push(child);
            }
        }
    }
    for (int i = 1; i <= 6; i++) cout << dist[i] << endl;
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

    graph[3].push_back(6);
    graph[6].push_back(3);

    graph[6].push_back(5);
    graph[5].push_back(6);

    bfs(1);
    //cout<<dist[6]<<endl;

    if(dist[6]==-1){
        cout<<"NO path"<<endl;
    }else{
        vector<int> path;
        int x=6;
        while(x!=-1){
            path.push_back(x);
            x=par[x];
        }
        reverse(path.begin(), path.end());
       for(auto x: path) cout<<x<<' ';
       cout<<endl;
    }

    return 0;
}
