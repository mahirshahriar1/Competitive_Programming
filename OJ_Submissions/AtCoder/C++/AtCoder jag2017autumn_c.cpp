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

int count_pfactors( int n ) {
    int cnt=0;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {         
        if ( n % primes[i] == 0 ) {
            while ( n % primes[i] == 0 ) {
                n /= primes[i];
                cnt++;
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        cnt++;;
    }
    return cnt;
}


int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
  
   sieve((int)1e6+10);
   int l,r;
   cin>>l>>r;

    int ans=0;
   for(int i=l;i<=r;i++){
        if(isprime[count_pfactors(i)])
            ans++;
   }
   cout<<ans<<endl;

    

}
