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


}

int main(){
  fastio  
  #ifndef ONLINE_JUDGE  
         freopen("input.txt", "r", stdin); 
         freopen("output.txt", "w",stdout);
  #endif

  int n,k;
  cin>>n>>k;
  deque<int> v;

  for(int i=0;i<n;i++)
    v.push_back(i+1);

  int change;
  for(int i=0;i<k;i++){
     cin>>change;
     change=change%n;
    while(change--){
      rotate(v.begin(),v.begin()+1,v.end());
    }
    cout<<v[0]<<' ';
    v.pop_front();
    n--;
  }
  cout<<endl;

}
