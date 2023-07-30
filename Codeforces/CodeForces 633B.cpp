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


void solve()
{
    ll n;
    cin>>n;
    ll ans1=0;
    ll ans2=0;
    ll l=1,r=1e10;
    while(l<=r)
    {
        ll mid=(l+r)>>1;

        ll temp=trailingZeroes(mid);
        if(temp==n)
        {
            ans1=mid;
            l=mid+1;
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
     l=1,r=1e10;
    while(l<=r)
    {
        ll mid=(l+r)>>1;

        ll temp=trailingZeroes(mid);
        if(temp==n)
        {
            ans2=mid;
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

    if(!ans1||!ans2)
        cout<<0<<endl;
    else{
        cout<<abs(ans2-ans1)+1<<endl;
        for(int i=min(ans1,ans2);i<=max(ans2,ans1);i++)
            cout<<i<<' ';
        cout<<endl;
    }

}



void solve2()
{
    ll n;
    cin>>n;


    ll i=0;

    vector<ll> v;
    while(1)
    {
        ll val=trailingZeroes(++i);
        if(val==n)
            v.push_back(i);
        if(val>n)
            break;
    }
    if(v.size()==0)
        cout<<0<<endl;
    else{
        cout<<v.size()<<endl;
        for(auto x:v)
            cout<<x<<' ';
        cout<<endl;
    }
}


int main()
{
    fastio;

    solve();

    return 0;
}
