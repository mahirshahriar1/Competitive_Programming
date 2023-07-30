#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

vector<int> graph[1005];
int dist[1005];

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
   
}

void cleargraph(){
    for(int i=0;i<1005;i++){
        graph[i].clear();
    }
}


int main(){
    fastio  
    // #ifndef ONLINE_JUDGE  
    //        freopen("input.txt", "r", stdin); 
    //        freopen("output.txt", "w",stdout);
    // #endif

    int t;
    cin>>t;

    while(t--){
        cleargraph();

        int n,e;
        cin>>n>>e;

        while(e--){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int source;
        cin>>source;
        bfs(source);

        for(int i=1;i<=n;i++){
            if(i==source) continue;
            if(dist[i]!=-1){
                cout<<dist[i]*6<<' ';
            }else{
                cout<<dist[i]<<' ';
            }
        }
        cout<<endl;

    }

    return 0;
}
