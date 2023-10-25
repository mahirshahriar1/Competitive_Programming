#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <pair<ll,ll>> pfactors_pair(ll n)
{
    vector<pair<ll,ll>>result;
    for(ll p=2;p*p<=n;p++)
    {
        ll cnt=0;
        if(n%p)
            continue;
        while(n%p==0)
        {
            n/=p;
            ++cnt;
        }
        result.push_back({p,cnt});
    }
    if(n>1)
        result.push_back({n,1});
    return result;
}


bool edit(pair<ll,ll> p1, pair<ll,ll> p2)
{
    return p1.second>p2.second;
}

void solve()
{

    ll n;
    cin>>n;

    vector<pair<ll,ll>> factors=pfactors_pair(n);

    sort(factors.begin(),factors.end(),edit);

    vector<ll> result;

    for(ll i=0;i<factors[0].second;i++)
        result.push_back(factors[0].first);

    for(ll i=1;i<factors.size();i++)
    {
        for(ll j=0;j<factors[i].second;j++)
        {
            result.back()*=factors[i].first;
        }
    }

    cout<<factors[0].second<<endl;
    for(auto x:result)
        cout<<x<<' ';
    cout<<endl;


}


int main()
{
    fastio;

    int t,kas=0;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
