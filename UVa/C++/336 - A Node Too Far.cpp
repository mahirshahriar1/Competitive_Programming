#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;


map<int,vector<int>> graph;
int cnt;
int a,b,kas;

void bfs(int source) {
    map<int, int> dist;
    queue <int> q;
    dist[source] = 0;
    q.push(source);  
    cnt++; 
    while (!q.empty()) {
        int f = q.front();        
        q.pop();
        for (int i = 0; i < graph[f].size(); i++) {
            int child = graph[f][i];
            if (!dist.count(child)) {
                dist[child] = dist[f] + 1;
                if(dist[child]<=b)              
                    q.push(child),cnt++;
            }
        }
    }
   
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int nc;
    while(cin>>nc, nc!=0){
        graph.clear();
      
        for(int i=0;i<nc;i++){
            cin>>a>>b;            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(cin>>a>>b){
            if(a==0 && b==0) break;            
            cnt=0;
            bfs(a);          
            cout<<"Case "<<++kas<<": "<<graph.size()-cnt<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
        }
    }

}
