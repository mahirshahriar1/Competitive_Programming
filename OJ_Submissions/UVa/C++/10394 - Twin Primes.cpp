#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <bool> isprime;

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

}

vector <ll> t_primes;
void twin_prime()
{
    for(int i=2;i<=20000000;i++)
    {
        if(isprime[i]&&isprime[i+2])
            t_primes.push_back(i);
    }
}

int main()
{
    fastio;

    sieve(20000000);
    twin_prime();

    ll x;
    while(cin>>x)
    {
        cout<<"("<<t_primes[x-1]<<", "<<t_primes[x-1]+2<<")"<<endl;
    }


}
