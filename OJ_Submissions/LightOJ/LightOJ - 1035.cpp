#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


vector <bool> isprime;
vector <int> primes;

void sieve(int n) //prime
{
    isprime.assign(n+1,true);

    isprime[0]=isprime[1]=false;

    for(int i=2; i*i<=n; i++)
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

vector <pair<ll,ll>> pfactors_fact_pair(ll n)
{
    vector<pair<ll,ll>>result;
    for ( ll i = 0; i < primes.size() && primes[i] <= n; i++ )
    {
        ll x = n;
        ll freq = 0;

        while ( x / primes[i] )
        {
            freq += x / primes[i];
            x = x / primes[i];
        }

        result.push_back({primes[i],freq});
    }

    return result;
}



int main()
{

    fastio;
    sieve(1000);
    int t,kase=0;
    cin>>t;
    while(t--)
    {
        ll a;
        cin>>a;

        vector <pair<ll,ll>> factors=pfactors_fact_pair(a);
        cout<<"Case "<<++kase<<": "<<a<<" = ";
        for(auto itr=factors.begin(); itr!=factors.end(); itr++)
        {
            if(prev(factors.end())==itr)
                cout<<(*itr).first<<" ("<<(*itr).second<<") ";
            else
                cout<<(*itr).first<<" ("<<(*itr).second<<") * ";

        }
        cout<<endl;
        factors.clear();

    }

}
