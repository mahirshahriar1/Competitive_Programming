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


ll arr[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    
ll dp[11][30000+5];
ll func(ll ind , ll amount){
    //cout<<amount<<endl;
    if(amount==0) return 1LL;
    if(ind>=11) return 0;          
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    ll val=func(ind+1,amount);
    if(amount-arr[ind]>=0) val+=func(ind,amount-arr[ind]);
    return dp[ind][amount]=val;
}



int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    double n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n){      
        double x=n;
        n*=100;    
        ll check=n;
        if(check==0) break;
        //cout<<(ll)(n+eps)<<endl;           
        printf("%6.2lf %16lld\n",x,func(0,n+eps));
    }
    return 0;

}
