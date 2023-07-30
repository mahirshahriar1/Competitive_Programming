#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

const ll mod=1000000007;
ll kas=0;

ll binExpRecurMod(ll a, ll b,ll m)  //pow function
{
    if(b==0) return 1;
    ll res= binExpRecurMod(a,b/2,m);
    if(b&1)
        return a%m*res%m*res%m;
    else
        return res%m*res%m;
}

void solve()
{

    ll n;
    cin>>n;

    cout<<"Case #"<<++kas<<": "<<(binExpRecurMod(2,n-1,mod)*n)%mod<<endl;

}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
