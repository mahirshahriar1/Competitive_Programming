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

const int N = 100000;
vector <int> graph[ N ];
bool visited[ N ];
int cnt;

void dfs(int node) {   
    cnt++;
   //cout<<node<<endl;
    visited[node] = true;    
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];      
        if (!visited[child]) {            
            dfs(child);
        }
    }
}
void cleargraph(){
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){        
        int n,m,l;
        cin>>n>>m>>l;
        cleargraph();
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);           
        }
        cnt=0;
        memset(visited,false,sizeof(visited));            
        for(int i=0;i<l;i++){
            int nod;
            cin>>nod;
            if(!visited[nod])
                dfs(nod);           
        }       
        cout<<cnt<<endl;
    }
    
}
