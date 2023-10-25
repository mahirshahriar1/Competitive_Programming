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
  int n;
  cin>>n;

  vector<int> a(n),b(n);
  takeInput(a);
  takeInput(b);

  vector<int> ans;

  for(int i=0;i<n;i++){
    if(i==0){
      ans.push_back(b[i]-a[i]);
      continue;
    }
    ans.push_back(min(b[i]-a[i],b[i]-b[i-1]));
  }
  print(ans)

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
