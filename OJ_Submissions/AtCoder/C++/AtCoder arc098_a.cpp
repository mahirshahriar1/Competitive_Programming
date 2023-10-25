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
   
    int n;
    cin>>n;
    string x;
    cin>>x;
    string s='.'+x;
    
    vector<int> e(n+1,0),w(n+1,0);
    for(int i=1;i<=n;i++){
        if(s[i]=='W'){
            w[i]=1;
        }else{
            e[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        e[i]+=e[i-1];
        w[i]+=w[i-1];
    }

    ll ans=INT64_MAX;
    
    for(int i=1;i<=n;i++){
        ll x=w[i-1]+e[n]-e[i];        
        ans=min(x,ans);
    }
    cout<<ans<<endl;    



    return 0;
}
