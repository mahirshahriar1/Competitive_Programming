#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
typedef long long int ll;
using namespace std;

vector <ll> NOD;

void sieve_NOD(ll n)
{
    NOD.assign(n+1, 0);

    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n; j+=i)
        {
            ++NOD[j];
        }
    }
}

bool comp(pair<ll,ll> p1, pair<ll,ll> p2)
{
    if(p1.second==p2.second)
        return p1.first>p2.first;

    return p1.second<p2.second;

}

int main()
{
    fastio
    sieve_NOD(1000);

    vector <pair<ll,ll>> v(NOD.size());
    for(ll i=0;i<NOD.size();i++)
    {
        v[i].first=i;
        v[i].second=NOD[i];
       // v.push_back({i,NOD[i});  vector <pair<ll,ll>> v;

    }

    sort(v.begin(), v.end(), comp);

    ll t,c=0; cin>>t;

    while(t--)
    {
        ll x;
        cin>>x;
        cout<<"Case "<<++c<<": "<<v[x].first<<endl;
    }


    return 0;
}
