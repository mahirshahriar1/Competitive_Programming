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

struct node{
    int val;
    int weight;
};

const int N=1e5+10;
vector<node> graph[N];
bool vis[N];
vector<int> ans(N,-1);

void dfs(int src1){
    if(vis[src1]) return;
    vis[src1]=1;
    //cout<<src<<endl;
    for(auto &x: graph[src1]){
        if(x.weight & 1){
            ans[x.val]=1-ans[src1];
            //cout<<src<<' '<<ans[x.val]<<endl;
        }else {

            ans[x.val]=ans[src1];
            //cout<<src<<' '<<ans[x.val]<<endl;
        }
        dfs(x.val);
    }

}


int main(){
    fastio

    int n;
    cin>>n;

    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    ans[0]=0;


    memset(vis,0,sizeof(vis));
    dfs(0);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<'\n';
    }

}

/*10
2 5 2
2 3 9
1 3 8
3 4 1
4 6 1
1 7 5
7 8 5
8 9 7
7 10 2
*/


