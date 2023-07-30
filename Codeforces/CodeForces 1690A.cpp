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

  if(n%3==0){
    cout<<n/3<<' '<<n/3+1<<' '<<n/3-1;
  }else{
    if(n%3==1){
      cout<<n/3<<' '<<n/3+2<<' '<<n/3-1;
    }else{
      cout<<n/3+1<<' '<<n/3+2<<' '<<n/3-1;
    }
  }
  cout<<endl;

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
