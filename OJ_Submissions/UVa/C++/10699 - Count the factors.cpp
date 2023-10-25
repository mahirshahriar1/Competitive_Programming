#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;


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

    for(int i=2;i<=n;i++){
        if(isprime[i])
            primes.push_back(i);
    }

}

int pfactors_v2(int n) 
{
    set<int> s;
    for(ll p:primes)
    {
        if(p*p>n)
            break;
        while(n%p==0)
        {
            n/=p;
            s.insert(p);
        }

    }
    if(n>1)
        s.insert(n);

    return s.size();
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    sieve(1000000+10);

    int n;
    while(cin>>n, n!=0){
       cout<<n<<" : "<<pfactors_v2(n)<<endl;        
    }

    return 0;
}
