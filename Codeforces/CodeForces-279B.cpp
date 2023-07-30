#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    ll n,t;
    cin>>n>>t;

    ll arr[n+1], sum[n+1];
    for(ll i=1; i<=n; i++)
    {
        cin>>arr[i];
        sum[i]=arr[i]+sum[i-1];
    }
    ll ans=0;

    for(ll i=0; i<n; i++)
    {
        ll val=0;
        ll l=i;
        ll r=n;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(sum[mid]-sum[i]>t)
            {
                r=mid-1;
            }
            else if(sum[mid]-sum[i]<=t)
            {
                val=mid-i;
                l=mid+1;
            }
        }

        ans=max(ans,val);

    }
    cout<<ans<<endl;

}


int main()
{
    fastio;

    solve();

    return 0;
}
