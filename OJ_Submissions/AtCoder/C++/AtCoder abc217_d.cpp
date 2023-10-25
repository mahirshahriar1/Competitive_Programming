#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    map<ll,ll> m;

    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        m[x]++;
    }

    ll count=0;

    for(auto x:m)
    {
        if(x.second>x.first)
        {
            count+=x.second-x.first;
        }
        else if(x.second<x.first)
        {
            count+=x.second;
        }
    }
    cout<<count<<endl;


    return 0;
}



