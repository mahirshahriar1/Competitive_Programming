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
  vector<int> v(n);
  takeInput(v);  
  
  vector<int> arr=v;
  sort(range(v));
  int cnt=0;

  for(int i=0;i<n;i++){
    if(arr[i]!=v[i])  
        cnt++;
  }

  cout<<cnt/2<<endl; 
  
  // 1 1 0 0 1 0 0 1 1 1 0
  // 0 0 0 0 0 1 1 1 1 1 1
  // cnt=6, ans=3
  // 0 0 0 1 1 1 1 1 - - -

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
