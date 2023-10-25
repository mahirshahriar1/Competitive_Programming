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
    ll n;
    cin>>n;
    vector<ll> v(n),even,odd;
    ll sum=0;

    for(auto x:v){
        cin>>x;
        sum+=x;
        if(x%2)odd.push_back(x);
        else   even.push_back(x);
    }
    if(sum%2==0){
        cout<<0<<endl;
        return;
    }
    ll ans=INT_MAX;

    for(auto x: even){
        ll cnt(0);
        while(x!=0 and x%2!=1){
            x/=2;
            cnt++;
        }
        if(cnt) ans=min(ans,cnt);
    }
    for(auto x: odd){
        ll cnt(0);
        while(x!=0 and x%2!=0){
            x/=2;
            cnt++;
        }
        if(cnt) ans=min(ans,cnt);
    }    
    
    cout<<ans<<endl;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
