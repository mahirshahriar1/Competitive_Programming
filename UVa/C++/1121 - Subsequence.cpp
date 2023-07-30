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



int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll n,s;
    while(cin>>n>>s){
        vector<ll> v(n);
        takeInput(v);
        ll sum=0,ind=0,ans=INT_MAX;
        bool flag=false;
        for(int i=0;i<n;i++){
            sum+=v[i];
            while(sum>=s){                
                ans=min(ans,i+1-ind);                
                flag=true;
                sum-=v[ind++];         
            }
        }  
        if(flag){
            cout<<ans<<endl;    
        }else{
            cout<<0<<endl;
        }

    }

}
