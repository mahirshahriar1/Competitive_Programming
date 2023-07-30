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


void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> prev(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        prev[b]=max(prev[b],a);
    }

    ll ans=0,last=0;
    for(int i=1;i<=n;i++)
    {
        last=max(last,(ll)prev[i]);       
        ans+=(i-last);       
    }
    cout<<ans<<endl;
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
