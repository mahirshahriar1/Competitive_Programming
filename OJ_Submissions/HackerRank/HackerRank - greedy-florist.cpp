#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

bool comp(ll a,ll b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;

    cin>>n>>k;

    vector <ll> v;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),comp);

    vector <ll> f(k);

    ll sum(0), j(0);

    for(int i=0;i<n;i++)
    {
        sum+=((f[j]+1)*v[i]);
        f[j]++;
        j=(j+1)%k;
    }
    cout<<sum<<endl;



    return 0;
}

