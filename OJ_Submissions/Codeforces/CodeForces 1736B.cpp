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

int lcm(int a,int b){
     return a*b/__gcd(a,b);
}

void solve(){
     int n;
     cin>>n;
     vector<int> v(n);
     takeInput(v)
     if(n==1){
          cout<<"YES"<<endl;
          return;
     }

     vector<int> ans(n+1);

     ans[0]=v[0];
     ans[n]=v[n-1];
     for(int i=1;i<n;i++){
          ans[i]=lcm(v[i],v[i-1]);
     }
     for(int i=0;i<n;i++){
          if(v[i]!=__gcd(ans[i],ans[i+1])){
               cout<<"NO"<<endl;
               return;
          }
     }
     cout<<"YES"<<endl;

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
     // cout<<__gcd(4,4);
     // cout<<__gcd(4,2);
     // cout<<__gcd(4,6);
     //cout<<__gcd(6,12)<<endl;
     return 0;
}
