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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1299709);

    ll x;

    while(cin>>x, x!=0)
    {
        if(x==2)
        {
         cout<<0<<endl;
         continue;
        }

        auto itr=lower_bound(primes.begin(), primes.end(),x);
        if(*itr==x)
            cout<<"0"<<endl;
        else
            cout<<*itr-*(prev(itr))<<endl;
    }



}

