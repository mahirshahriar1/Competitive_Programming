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


bool ok(const vector<ll>& v,ll n,ll m,ll mid){
    ll sum=0;
    for(ll i=0;i<n;i++){
        if(v[i]<=mid) continue;
        sum+=v[i]-mid;
    }
    return (sum>=m);
}

int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
  
    
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    ll mx=-1;
    for(auto& x:v){
        cin>>x;
        mx=max(mx,x);
    }

    ll l=0,r=mx;
    ll ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(ok(v,n,m,mid)){     
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    

}
