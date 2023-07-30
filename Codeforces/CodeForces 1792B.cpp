#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

void solve(){
    ll a,b,c,d;
    ll ans=0;
    cin>>a>>b>>c>>d;

    ans+=a;
    if(!ans){
        cout<<1<<endl;
        return;
    }
    ans+=2*min(b,c);

    ans += min(a + 1, b-min(b,c) + c-min(b,c) + d );
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
