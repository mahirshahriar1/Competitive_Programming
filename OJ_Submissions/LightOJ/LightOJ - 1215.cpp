#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

ll GCD(ll a, ll b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}

ll lcm(ll a, ll b)
{
    return (a/GCD(a,b))*b;
}

vector<ll> divisors(ll n)
{
    vector<ll> div;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (n / i != i)
            {
                div.push_back(n / i);
            }
        }
    }
    sort(div.begin(), div.end());
    return div;
}

int main()
{
    fastio;
    ll n,c=0;
    cin>>n;
    while(n--)
    {
        ll a,b,l;
        cin>>a>>b>>l;
        vector <ll> v=divisors(l);
        ll lcm_ab=lcm(a,b);

        bool flag=true;
        for(auto x:v)
        {
            if(lcm(lcm_ab,x)==l)
            {
                printf("Case %lld: %lld\n",++c, x);
                flag=false;
                break;
            }

        }
        if(flag)
            printf("Case %lld: impossible\n",++c);
        v.clear();

    }

}
