#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

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

void solve(){
    int n,m;
    cin>>n>>m;

    auto itr=lower_bound(primes.begin(),primes.end(), n);
    if(*itr>=m){
        cout<<"No jumping champion"<<endl;
        return;
    }
    map<int, int> mp;
    for(int i=itr-primes.begin();primes[i+1]<=m;i++){
        int diff=primes[i+1]-primes[i];
        mp[diff]++;
    }

    if(mp.size()==1){
        auto itr=mp.begin();
        cout<<"The jumping champion is "<<itr->first<<endl;
        return;
    }

    int freq=1,val=0;
    for(auto x:mp){
        if(x.second>freq){
            freq=x.second;
            val=x.first;
        }
    }

    if(freq>1){
        bool ok=true;
        int cnt=0;
        for(auto itr:mp){
            if(freq==itr.second){
                cnt++;
            }
            if(cnt==2){
                ok=false;
                break;
            }
        }

        if(ok){
            cout<<"The jumping champion is "<<val<<endl;
        }
        else{
            cout<<"No jumping champion"<<endl;
            return;
        }
    }else{
        cout<<"No jumping champion"<<endl;
        return;
    }

}

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif  

    sieve(1e7);
  
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    
}                                          
