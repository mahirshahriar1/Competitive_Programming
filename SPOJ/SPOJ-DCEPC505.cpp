#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


vector <bool> isprime;
vector <ll> primes;

void sieve(int n)
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

int main()
{
    fastio;
    sieve(2e7);

    vector <ll> v;

    for(int i=0;i<primes.size();i++)
    {
        for(int j=i+1;j<primes.size()&&primes[i]*primes[j]<=2e7;j++)
           v.push_back(primes[i]*primes[j]);
    }

    sort(v.begin(),v.end());
    int t;
    cin>>t;
    while(t--)
    {
        ll x;cin>>x;
        cout<<v[x-1]<<endl;
    }


}
