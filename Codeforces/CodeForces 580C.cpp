#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=(int)1e5+10;

vector<int> graph[N],cats(N);
bool visited[N];
int n,m,ans,catCount[N];

void dfs(int node){
    visited[node]=true;
    if(catCount[node]>m) {
        return;
    }

    int cnt=0;
    for(auto x: graph[node]){
        if(visited[x]) continue;   

        if(cats[x]) catCount[x]=catCount[node]+1;
        else        catCount[x]=0; 
   
        dfs(x); 
        cnt++;
    }

    if(cnt==0) {        
        ans++;          
    }
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
   
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>cats[i];
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    catCount[1]=cats[1];

    dfs(1);
    cout<<ans<<endl;

}
