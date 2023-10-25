#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
#define mod 998244353

ll fact(ll x)
{
    ll ans=1;
    for(ll i=x;i>0;i--)
    {
        ans=(ans%mod)*(i%mod);
    }
    return ans%mod;
}


int main()
{
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        int temp;
        cin>>temp;
        if(temp%2)
        {
            cout<<0<<endl;
            continue;
        }
        ll ans=fact(temp/2);
        cout<<(ans*ans)%mod<<endl;

    }




}

