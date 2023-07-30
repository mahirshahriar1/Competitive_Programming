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

const int arr[]={1,5,10,25,50};

int dp[7][10000];
int func(int ind , int amount){
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];

    int ways=0;
    for(int coin=0;coin<=amount;coin+=arr[ind]){
        ways+=func(ind-1,amount-coin);
    }

    return dp[ind][amount]=ways;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    int n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n){
        cout<<func(4,n)<<endl;
    }
    return 0;
}
