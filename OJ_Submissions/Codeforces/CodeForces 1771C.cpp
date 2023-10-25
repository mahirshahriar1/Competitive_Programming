#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
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


void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll cnt=0;
    for(auto &x:v){
        cin>>x;
        if(x%2==0)cnt++;
    }
    if(cnt>1){
        cout<<"YES"<<endl;
        return;
    }

    map <ll,ll> freq;
    for(ll i=0;i<n;i++){
        ll val=v[i];
        for(ll j=0;primes[j]*primes[j]<=val;j++){
            if(val%primes[j]==0){
                freq[primes[j]]++;
                while(val%primes[j]==0){
                    val/=primes[j];
                }
            }
        }
        if(val>1){
            freq[val]++;
        }
    }
  
    for(auto x:freq){
        if(x.second>1){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl; 

}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    sieve(32000);
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
