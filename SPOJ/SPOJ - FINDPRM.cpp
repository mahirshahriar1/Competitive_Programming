#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl '\n'

vector <bool> isprime;
vector<int> ans(10000000+10,0);
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
    for(int i=0;i<=n;i++){
        ans[i]+=ans[i-1];
        if(isprime[i]){
            ans[i]++;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(10000000);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]-ans[n/2]<<endl;
    }


}
