#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

ll power_mod(ll a, ll b,ll m)
{
    if(b==0) return 1;
    ll res= power_mod(a,b/2,m);
    if(b&1)
        return a%m*res%m*res%m;
    else
        return res%m*res%m;
}

const double eps = 1e-9;
int leadingDigit(ll n, ll k )
{
    double val=k*log10(n);

    double p=val-floor(val+eps);

    double ans=pow(10,p);

    return floor(ans*100+eps);
}


int main()
{

    fastio;
    ll t;
    cin>>t;

    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<leadingDigit(a,b)<<"...";
        ll temp=power_mod(a%1000,b,1000);
        if(temp>99)
            cout<<temp<<endl;
        else if(temp>9&&temp<100)
              cout<<"0"<<temp<<endl;
           else
              cout<<"00"<<temp<<endl;

    }

}
