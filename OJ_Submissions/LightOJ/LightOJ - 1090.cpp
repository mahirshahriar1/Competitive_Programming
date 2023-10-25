#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

ll trailFact(ll n, ll p)
{
    ll ans=0;
    while((n/p)>0)
    {
        ans+=(n/p);
        n/=p;
    }

    return ans;
}

ll func(ll n,ll x)
{
    ll cnt=0;
    while(n%x==0)
    {
        cnt++;
        n/=x;
    }
    return cnt;
}

void solve(int kas)
{
    ll n,r,p,q,nr;
    cin>>n>>r>>p>>q;

    nr=n-r;

    ll a=trailFact(n,2);
    ll b=trailFact(n,5);

    ll c=trailFact(r,2);
    ll d=trailFact(r,5);

    ll e=trailFact(n-r,2);
    ll f=trailFact(n-r,5);

    ll g=func(p,2)*q;
    ll h=func(p,5)*q;

    ll ans=min(a-c-e+g,b-d-f+h);
    cout<<"Case "<<kas<<": "<<ans<<endl;

}


int main()
{
    fastio;
    int t,kas=0;
    cin>>t;

    while(t--)
    {
         solve(++kas);
    }


    return 0;
}
