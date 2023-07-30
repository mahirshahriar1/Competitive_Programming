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


ll dp[22][10000+10];
ll coins[22];
ll func(ll ind , ll amount){
    if(amount==0) return 1;
    if(ind>=21) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    ll val=func(ind+1,amount);
    if(amount-coins[ind]>=0) val+=func(ind,amount-coins[ind]);
    return dp[ind][amount]=val;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    for(int i=1;i<=21;i++){
        coins[i-1]=i*i*i;
    }

    ll n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n){
        cout<<func(0,n)<<endl;
    }


    return 0;
}
