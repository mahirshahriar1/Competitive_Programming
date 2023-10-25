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
   vector<ll> sumv(n,0);
 
   for(int i=0;i<n;i++){
            cin>>v[i];
        if(i==0){
            sumv[i]=v[i];
        }else{
            sumv[i]=v[i]+sumv[i-1];
        }      
   }

    map<ll,int> mp;
    ll cnt=0,mx=0;
    for(int i=n-1;i>=0;i--){ 
      mp[sumv[i]]++;
      mx=max(mx,(ll)mp[sumv[i]]);
      if(v[i]==0){
        cnt+=mx;
        mx=0;
        mp.clear();
      } 
    }
    cnt+=mp[0];
    cout<<cnt<<endl;   
  
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
