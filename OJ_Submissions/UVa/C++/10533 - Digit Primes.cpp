#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
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

ll digit_sum(ll n)
{
    ll sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    sieve(1000010);

    ll ans[1000010],cnt=0;

    for(ll i=0;i<=1000000;i++)
    {
        if(isprime[i]&&isprime[digit_sum(i)])
            cnt++;
        ans[i]=cnt;
    }

    ll test;
    scanf("%lld", &test);
    while(test--)
    {
        ll t1,t2;
        scanf("%lld %lld", &t1,&t2);
        ll res=ans[t2]-ans[t1-1];


       
        printf("%lld\n", res );

    }


}
