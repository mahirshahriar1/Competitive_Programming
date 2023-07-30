#include <bits/stdc++.h>
#define endl '\n'
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(100000);

    ll x;
    cin>>x;
    int j=0;
    if(x==1)
        cout<<"1\n"<<"1"<<endl;
    else if(x==2)
        cout<<"1\n"<<"1 1"<<endl;
    else
    {
        cout<<"2\n";
        for(int i=1; i<=x; i++)
        {
            if(primes[j]==i+1)
            {
                j++;
                cout<<"1 ";
            }
            else
                cout<<"2 ";
        }
        cout<<endl;
    }



}



