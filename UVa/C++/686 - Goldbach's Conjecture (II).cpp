#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

vector <bool> isprime;

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

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    sieve(1000000);
    ll x;
    while(cin>>x, x!=0)
    {
        ll end_ind=x, cnt=0;

        if(x==4)
            cout<<"1"<<endl;
        else
        {
            for(int i=3; i<=x/2; i++)
            {
                if(isprime[i]&&isprime[end_ind-i])
                {
                    //cout<<x<<" = "<<i<<" + "<<end_ind-i<<endl;
                    cnt++;
                }
            }

            cout<<cnt<<endl;

        }


    }
}


