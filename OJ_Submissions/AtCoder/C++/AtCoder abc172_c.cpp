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


int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
  
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);

    vector<ll> prefix_a(n+1),prefix_b(m+1);
    prefix_a[0]=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        prefix_a[i+1]=prefix_a[i]+a[i];
    }
    for(ll i=0;i<m;i++){
        cin>>b[i];
        prefix_b[i+1]=prefix_b[i]+b[i];
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        if(prefix_a[i] > k) 
            break;
        ll x=k-prefix_a[i];

        ll itr=upper_bound(range(prefix_b),x)-prefix_b.begin();
        
        if(itr==0) 
            continue;
        itr--;      
       
        ans = max(ans, i + itr);
    }
    cout<<ans<<endl;
    

}
