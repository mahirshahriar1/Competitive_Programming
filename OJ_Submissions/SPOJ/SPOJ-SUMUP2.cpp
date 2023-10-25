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

    for(int i=2;i<=n;i++){
        if(isprime[i])
            primes.push_back(i);
    }

}

ll sum(ll n)
{
    ll s=0;
    vector<ll> result;
    for(ll p:primes)
    {
        if(p*p>n)
            break;
            ll cnt=0;
        while(n%p==0)
        {
            n/=p;
          cnt++;
        }
        s=s+p*cnt;

    }
    if(n>1)
        s+=n;

    return s;
}

int main()
{
    fastio;

    sieve(1e8);

   ll t;
    while(cin>>t)
    cout<<sum(t)<<endl;

}
