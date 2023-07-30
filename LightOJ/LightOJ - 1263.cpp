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

const int N=1e4;
int money[N],kas;

vector <int> graph[ N ];
bool visited[ N ];

int cnt,cost;
set<int> s;
void dfs(int node) {  
    cnt++;
    cost+=money[node];
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];     
        if (!visited[child]) {   
            dfs(child);
        }
    }
    
}

bool bfs(int source) {   
    queue <int> q;  
    q.push(source);
    visited[source]=true;
    cnt++;
    cost+=money[source];
    while (!q.empty()) {
        int f = q.front(); 
        q.pop();
        for (int i = 0; i < graph[f].size(); i++) {
            int child = graph[f][i];
            if (visited[child] == false) {
                cnt++;
                cost+=money[child];
                visited[child]=true;     
                q.push(child);
            }
        }
    }
    if(cost%cnt==0){
        s.insert(cost/cnt);
        return true;
    }   
    return false;
}


void clear(){
    memset(money,0,sizeof(money));
    memset(visited,false,sizeof(visited));
    s.clear();
    for(int i=0;i<N;i++){
        graph[i].clear();
    }
}

void solve(){
    clear();

    cout<<"Case "<<++kas<<": ";    
    int n,m;
    cin>>n>>m;

    int tmoney=0;
    for(int i=1;i<=n;i++){
        cin>>money[i];
        tmoney+=money[i];
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int avg=tmoney/n;
    if(tmoney%n) {
        cout<<"No"<<endl;    
        return;
    }
    for(int i=1;i<=n;i++){
        cnt=0,cost=0;
        if(!visited[i]){
            if(!bfs(i)){
                cout<<"No"<<endl;
                return;
            }
            // if(cnt*avg!=cost){
            //     cout<<"No"<<endl;
            //     return;
            // }       /* dfs */    
  
        }
    }
    if(s.size()==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // /* dfs */ cout<<"Yes"<<endl;
    
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
