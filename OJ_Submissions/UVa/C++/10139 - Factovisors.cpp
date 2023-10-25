#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <bool> isprime;
vector <int> primes;

void sieve(ll n) //prime
{
    isprime.assign(n+1,true);

    isprime[0]=isprime[1]=false;

    for(ll i=2; i*i<=n; i++)
    {
        if(!isprime[i])
            continue;
        for(int j=i*i; j<=n; j+=i)
        {
            isprime[j]=false;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(isprime[i])
            primes.push_back(i);
    }

}

ll frequency(ll n,ll p)
{
    ll freq=0;
    while((n/p)>0)
    {
        freq+=(n/p);
        n/=p;
    }

    return freq;
}

void solve(ll a,ll b)
{
    vector<pair<ll,ll>> v;
    ll n=b;
    for(ll i=0; i<primes.size()&&primes[i]<=sqrt(n); i++)
    {
        ll freq=0;
        while(n%primes[i]==0)
        {
            freq++;
            n/=primes[i];
        }
        if(freq)
            v.push_back({primes[i],freq});

    }
    if(n>1)
        v.push_back({n,1});

    bool found=false;

    for(auto x: v)
    {
        if(frequency(a,x.first)<x.second)
        {
            found=true;
            break;
        }
    }

    if(!found)
        cout<<b<<" divides "<<a<<"!"<<endl;
    else
        cout<<b<<" does not divide "<<a<<"!"<<endl;
}


int main()
{
   fastio;

    sieve(1e7);

    ll a,b;

    while(cin>>a>>b)
    {
        solve(a,b);
    }



    return 0;
}
