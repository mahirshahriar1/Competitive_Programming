#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

vector <bool> isprime;
vector <int> primes;

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
    sieve(51);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w",stdout);
    #endif

    int n;
    cin>>n;
    ll arr[n];
    takeInput(arr)
    ll res=1e18;

    for(int i=0;i<(int)(1<<primes.size());i++){
        ll ans=1;
        for(int j=0;j<(int)primes.size();j++){
            if(i&(1<<j)){         
                ans*=primes[j];
            }
        }
        bool flag=true;
        for(auto x: arr){
            if(__gcd(x,ans)==1){
                flag=false;
                break;
            }
        }

        if(flag)
            res=min(res,ans);
    }
    cout<<res<<endl;


}
