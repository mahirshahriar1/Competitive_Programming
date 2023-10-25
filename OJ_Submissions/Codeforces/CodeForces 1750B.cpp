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

ll binExpRecur(ll a, ll b)  //power
{
    if(b==0) return 1;
    ll res= binExpRecur(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}


void solve(){
      int n;
      cin>>n;
      string s;
      cin>>s;

      int one=0,zero=0;
      for(auto x:s){
        if(x=='1') one++;
        else zero++;
      }
      
      if(zero==0){
        cout<<binExpRecur(one,2)<<endl;
        return;
      }else if(one==0){
        cout<<binExpRecur(zero,2)<<endl;
        return;
      }

      ll ans=0;
      for(int i=0;i<n;i++){
        char c=s[i];
        int cnt=0;
        for(int j=i;j<n;j++){
          if(s[j]!=c) break;
          cnt++;
          i=j;
        }
        ans=max(ans,binExpRecur(cnt,2));
      }
      if(zero and one) ans=max(ans, (ll)zero*one);
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
