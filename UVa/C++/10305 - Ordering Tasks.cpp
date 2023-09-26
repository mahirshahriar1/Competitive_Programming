#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

stack <int> stk;
void topsort(int v, vector <vector<int>> &graph, vector <bool> &visited){
    visited[v] = true;

    for (auto u : graph[v])
        if (!visited[u])
            topsort(u,graph,visited);
    stk.push(v);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m, n){
        vector <vector<int>> graph(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        vector <bool> visited(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visited[i])
                topsort(i,graph,visited);
        }
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();
        }
        cout<<endl;
    }
}