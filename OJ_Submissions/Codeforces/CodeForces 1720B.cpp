#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{
    ll n;
    cin>>n;

    deque<ll> dq;

    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        dq.push_back(temp);
    }

    sort(dq.begin(),dq.end());

    ll mn1=dq.front();    dq.pop_front();
    ll mn2=dq.front();

    ll mx1=dq.back();    dq.pop_back();
    ll mx2=dq.back();

    cout<<mx1-mn1+mx2-mn2<<endl;




}


int main()
{
    fastio;
    int t;cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
