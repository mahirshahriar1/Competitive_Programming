#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> divisors(ll x)
{
    vector<ll> div;
    for (ll i=1; i*i<=x; i++)
    {
        if (x%i==0)
        {
            div.push_back(i);
            if (x/i!=i)
                div.push_back(x/i);
        }
    }

    sort(div.begin(), div.end());
    return div;
}

int main()
{
    ll n;
    cin>>n;

    vector <ll> div=divisors(n);


    for(ll i=div.size()-1;i>=0;i--)
    {
        int flag=1;
        for(ll j=2;j*j<=div[i];j++)
        {
            if(div[i]%(j*j)==0)
            {
                flag=0;
                break;
            }
        }

        if(flag)
        {
            cout<<div[i]<<endl;
            return 0;
        }
    }


    return 0;
}
