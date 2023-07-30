#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long int ll;

vector <ll> graph[ N ];
bool visited[ N ];
ll cnt;

void dfs(ll node) { 
    cnt++;  
    visited[node] = true;
    for (ll i = 0; i < graph[node].size(); i++) {
        ll child = graph[node][i];       
        if (!visited[child]) {
            dfs(child);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    // #ifndef ONLINE_JUDGE  
    //        freopen("input.txt", "r", stdin); 
    //        freopen("output.txt", "w",stdout);
    // #endif

    ll n,p;
    cin>>n>>p;

    for(ll i=0;i<p;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> minus;
    for(ll i=0;i<n;i++){
        cnt=0;
        if(!visited[i]){
            dfs(i);
            minus.push_back(cnt);
        }
    }

    // for(auto x:minus){
    //     cout<<x<<' ';
    // }cout<<endl;

     ll ans=n*(n-1)/2;
    for(auto x:minus){
        ans-=x*(x-1)/2;
    }
    cout<<ans<<endl;



    return 0;
}
