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

const int N= 1e4+10;

bool flag;
vector <int> graph[ N ];
bool visited[ N ];

void dfs(int node) {   
    if(visited[node]) {
        flag=true;
        return;   
    }
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];     
        if (!visited[child]) {          
            dfs(child);
        }
    }
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif  
    
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(n-1!=m){
        cout<<"NO"<<endl;
        return 0;
    }

    dfs(1);   
    if(flag) goto label; //already visited node in the tree. two parents

    for(int i=1;i<=n;i++){
        if(!visited[n]){ //single parent node could not reach all nodes so not a tree
            flag=true;
            break;
        }
    }

    label:
    if(flag) cout<<"NO"<<endl;
    else     cout<<"YES"<<endl;

    return 0;

}
