#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <bool> isprime;
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
}



int main()
{

    fastio;
    sieve(1e6);

    ll t;
    cin>>t;
    while(t--)
    {
        ll x;cin>>x;
        ll tmp=sqrt(x);

        if(isprime[tmp]&&(tmp*tmp==x))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }

}
