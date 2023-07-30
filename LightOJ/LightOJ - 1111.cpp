#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=1010;
vector <int> graph[N];
bool visited[N];
int cnt[N];

void dfs(int node) {
    visited[node] = true;
    cnt[node]++;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];      
        if (!visited[child]) {      
            dfs(child);
        }
    }
}

void clear(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
    memset(cnt,0,sizeof(cnt));
}

int kas;

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        clear();
        int k,n,m;
        cin>>k>>n>>m;
        vector<int> v(k);
        for(auto &x: v) cin>>x;

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }
        for(int i=0;i<k;i++){
            memset(visited,false,sizeof(visited));
          // cout<<v[i]<<endl;
            dfs(v[i]);
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(cnt[i]>=k){
                res++;
            }
        }
        cout<<"Case "<<++kas<<": "<<res<<endl;

    }
}
