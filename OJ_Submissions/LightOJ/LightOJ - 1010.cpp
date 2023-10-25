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

int kas=0;

void solve(){
    int n,m,ans;
    cin>>n>>m;
    if(m==1||n==1){
        ans=max(n,m);
    }else if(n==2||m==2){
        ans=((m*n)/8)*4;
        if((m*n)%8>=4){
            ans+=4;
        }else{
            ans+=(m*n)%8;
        }        
    }else{
        ans=ceil((m*n)/2.0);
    }

    cout<<"Case "<<++kas<<": "<<ans<<endl;
}

int main(){
     
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
        
        
}
