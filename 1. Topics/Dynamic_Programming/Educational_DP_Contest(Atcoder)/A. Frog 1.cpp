#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const int N=1e5+10;
int h[N];
int dp[N];
int func(int i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];

    int cost=INT_MAX;

    cost=min(cost,func(i-1)+abs(h[i]-h[i-1]));
    
    if(i>1)
        cost=min(cost,func(i-2)+abs(h[i]-h[i-2]));
 
    return dp[i]=cost;
}
 

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>h[i]; 
    }
    cout<<func(n-1)<<endl;

    return 0;

}