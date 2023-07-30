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

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>v(n);
  takeInput(v);
  if(is_sorted(range(v))) {
    cout<<0<<endl;
    return;
  }

  ll cnt=0,num=1;
  for(auto x:v){
    if(x==num){
        num++;
        cnt++;
    }
  }
  cout<<(n-cnt+k-1)/k<<endl;
}

int main(){
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
