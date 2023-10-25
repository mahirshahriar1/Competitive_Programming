#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;

const int N=2010;


int n;
int value[N],sz[N];

int w;
int dp[N][N];

int knapsack2(int i,int curr_size){
    if(i>=n) return 0;
    if(curr_size==w) return 0;
    if(dp[i][curr_size]!=-1) return dp[i][curr_size];

    int val1=0,val2=0;

    if(curr_size+sz[i]<=w){
        val1=value[i]+knapsack2(i+1,curr_size+sz[i]);
    }
    val2=knapsack2(i+1,curr_size);

    return dp[i][curr_size]=max(val1,val2);
}

int knapsack(int i,int max_size){
    if(i>=n) return 0;

    if(dp[i][max_size]!=-1) return dp[i][max_size];

    int val1=0,val2=0;

    if(max_size-sz[i]>=0){
        val1=value[i]+knapsack(i+1,max_size-sz[i]);
    }
    val2=knapsack(i+1,max_size);

    return dp[i][max_size]=max(val1,val2);
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
   
    cin>>w;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>sz[i]>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack2(0,0)<<endl;
    
}
