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
  int n,k;
  cin>>n>>k;

  string s;
  cin>>s;

  vector<int> sum(n+1,0);

  for(int i=0;i<n;i++){
    sum[i+1]=sum[i]+(s[i]=='W');
  }
 // print(sum)

  int ans=INT_MAX;
  for(int i=0;i+k<=n;i++){
    ans=min(ans,sum[i+k]-sum[i]);
  }
  cout<<ans<<endl;
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
