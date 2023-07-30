#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    ll n,k;
    cin>>n>>k;

    ll l=1,r=INT_MAX;
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll val=mid-mid/n;

        if(val<k){
            l=mid+1;
        }
        else if(val>k){
            r=mid-1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }
    cout<<ans<<endl;
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
