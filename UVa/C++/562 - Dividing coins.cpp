#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;


int coins[105];
int dp[105][500*105];
int n;
int knapsack(int i,int w){
    if(i>=n) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int val1=0,val2=0;

    if(w-coins[i]>=0){
        val1=coins[i]+knapsack(i+1,w-coins[i]);
    }
    val2=knapsack(i+1,w);
    
    return dp[i][w]=max(val1,val2);
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>coins[i];
            sum+=coins[i];
        }
        cout<<sum-2*knapsack(0,sum/2)<<endl;
    }
}
