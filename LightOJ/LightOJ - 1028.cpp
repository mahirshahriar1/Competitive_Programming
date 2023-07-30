#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <bool> isprime;
vector<int> prime;

void sieve(ll n)
{
    isprime.assign(n+1,true);
    isprime[0]=isprime[1]=false;

    for(ll i=2;i*i<=n;i++)
    {
        if(!isprime[i])
            continue;
        for(ll j=i*i;j<=n;j+=i)
            isprime[j]=false;
    }


    for(ll i=2;i<=n;i++)
    {
        if(isprime[i])
            prime.push_back(i);
    }
}


ll NOD_pfactor(ll n) {
    ll sqrtn = sqrt (n);
    ll res = 1;
    for ( ll i = 0; i < prime.size() && prime[i] <= sqrtn; i++ )
    {
        if ( n % prime[i] == 0 )
        {
            ll p = 0;
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;
            res *= p;
        }
    }
    if ( n != 1 )
        res *= 2;
    return res;
}


int main()
{

    fastio;
    sieve(1e7);


    ll t, kase=0;
    cin>>t;
    while(t--)
    {
        ll x;cin>>x;
        cout<<"Case "<<++kase<<": "<<NOD_pfactor(x)-1<<endl; // -1 bcz base cannot be 1  but 1 is a divisor

    }

}
