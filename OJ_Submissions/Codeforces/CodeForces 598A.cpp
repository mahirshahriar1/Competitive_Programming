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

vector<int> pow2;
void sieve(){
    int i=1;
    for(;i<=1e9;i*=2){
        pow2.push_back(i);
    }
    pow2.push_back(i);
}

void solve(){
    ll n;
    cin>>n;
    ll sum=n*(n+1)/2;
    for(int i=1;i<=n;i*=2){
        sum-=2*i;
    }
    cout<<sum<<endl;
}
int main()
{
   fastio  
   #ifndef ONLINE_JUDGE  
          freopen("input.txt", "r", stdin); 
          freopen("output.txt", "w",stdout);
   #endif
   
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
