#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

ll trailingZeroes(ll n)
{
    ll ans=0;
    ll p=5;
    while((n/p)>0)
    {
        ans+=(n/p);
        n/=5;
    }

    return ans;
}


ll solve()
{
    ll n;
    cin>>n;
    ll ans =-1;
    ll l=1,r=1e10;
    while(l<=r)
    {
        ll mid=(l+r)>>1;

        ll temp=trailingZeroes(mid);
        if(temp==n)
        {
            ans=mid;
            r=mid-1;
        }
        else if(temp<n)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}


int main()
{
    fastio;

    int t,ks=0;
    cin>>t;
    while(t--)
    {
        ll val=solve();
        if(val!=-1)
            cout<<"Case "<<++ks<<": "<<val<<endl;
        else
            cout<<"Case "<<++ks<<": "<<"impossible"<<endl;
    }

    return 0;
}
