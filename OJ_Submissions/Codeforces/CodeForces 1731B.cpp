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

const int M = 1e9 + 7;



ll binExpRecurMod(ll a, ll b,ll m)  
{
    if(b==0) return 1;
    ll res= binExpRecurMod(a,b/2,m);
    if(b&1)
        return a%m*res%m*res%m;
    else
        return res%m*res%m;
}

ll eqn1(ll n)
{
    ll ans=(((n*(n+1))%M)*(2*n+1)%M)%M;;
    ans=(ans*binExpRecurMod(6, M-2,M))%M;
    
    return ans;
}
ll eqn2(ll n)
{
    ll ans=(n*(n+1))%M;
    ans=(ans*binExpRecurMod(2, M-2,M))%M;
    
    return ans;
}


void solve()
{
    ll n;
    cin>>n;
        
    ll ans=0;        
    ans=eqn1(n)%M+eqn1(n-1)%M+eqn2(n-1)%M;
    ans=(ans*2022)%M;     

    cout<<ans<<endl;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
