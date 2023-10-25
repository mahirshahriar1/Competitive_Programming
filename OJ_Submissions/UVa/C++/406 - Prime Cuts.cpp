#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

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
    primes.push_back(1);  // considering 1 as prime as well
    for(ll i=2; i<=n; i++)
    {
        if(isprime[i])
            primes.push_back(i);
    }

}


int main()
{
    fastio

    sieve(1002);


    ll n,c,i,j;

    while( cin>>n>>c)
    {
        ll arr[1002];
        cout<<n<<" "<<c<<":";
        if(n==1)
        {
            cout<<" 1";
        }  // the condition is not necessary 
        else
        {
            int cnt=0;
            for(i=0; i<primes.size(); i++)
            {
                if(primes[i]<=n)
                    arr[cnt++]=primes[i];
                else
                    break;
            }

            if(cnt%2)
                c=2*c-1;
            else
                c=2*c;

            if(c>cnt)  // if c (range) exceeds prime number array size. then we need to restrict the c.
                c=cnt;

            for(i = cnt/2-c/2, j = 0; j < c; j++, i++)  
                cout<<" "<<arr[i];

        }
        cout<<endl;
        cout<<endl;

    }


}
