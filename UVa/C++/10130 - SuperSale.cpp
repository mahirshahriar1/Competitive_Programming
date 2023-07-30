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

int n;
int price[1100],weight[1010];

int dp[1100][40];

int knapsack(int i,int w){
    if(i>=n) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int val1=0,val2=0;

    if(w-weight[i]>=0){
        val1=price[i]+knapsack(i+1,w-weight[i]);
    }
    val2=knapsack(i+1,w);
    
    return dp[i][w]=max(val1,val2);
}


void solve(){    
    cin>>n;    
    for(int i=0;i<n;i++){
        cin>>price[i]>>weight[i];
    }
    int g;
    cin>>g;   
    
    memset(dp,-1,sizeof(dp));

    ll ans=0;
    for(int i=0;i<g;i++){
        int x; cin>>x;
        ans+=knapsack(0,x);
    }
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
