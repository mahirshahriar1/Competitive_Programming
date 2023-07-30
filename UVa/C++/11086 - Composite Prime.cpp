#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


vector <bool> isprime;
vector <ll> primes;

void sieve(ll n)
{
    isprime.assign(n+1,true);

    isprime[0]=isprime[1]=false;


    for(ll i=2; i*i<=n; i++)
    {
        if(!isprime[i])
            continue;
        for(ll j=i*i; j<=n; j+=i)
        {
            isprime[j]=false;
        }
    }

    for(ll i=2;i<=n;i++){
        if(isprime[i])
            primes.push_back(i);
    }

}

vector <ll> comp_primes;

void sieve_comp()
{
    for(int i=0;i<primes.size();i++)
    {
        for(int j=i;primes[i]*primes[j]<=2e7;j++)
        {
            comp_primes.push_back(primes[i]*primes[j]);
        }
    }
    sort(comp_primes.begin(),comp_primes.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(2e7);

    sieve_comp();

    ll t;

    while(cin>>t)
    {
        vector<ll> v;
        ll cnt=0;
        for(int i=0;i<t;i++)
        {
            ll in;
            cin>>in;
            v.push_back(in);
        }
        for(int i=0;i<t;i++)
        {
            auto itr=lower_bound(comp_primes.begin(),comp_primes.end(),v[i]);
            if(*itr==v[i])
                cnt++;
        }
        cout<<cnt<<endl;

    }

    return 0;
}
