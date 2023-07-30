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

int m,c, price[25][25];
int dp[210][25];

int shop(int money, int g){
    if(money<0) return -INT_MAX;
    if(g==c) return m-money;
    if(dp[money][g]!=-1) return dp[money][g];

    int ans=-1;
    for(int x=1;x<=price[g][0];x++) 
        ans=max(ans,shop(money-price[g][x],g+1));
    /*
    if(cnt<=price[g][0]){    
        ans=max(ans,shop(money,g,cnt+1));
        ans=max(ans,shop(money-price[g][cnt],g+1,1));
    }
    */
    
    return dp[money][g]=ans;
}

void solve(){
    cin>>m>>c;
    for(int i=0;i<c;i++){
        cin>>price[i][0];
        for(int j=1;j<=price[i][0];j++)
            cin>>price[i][j];
    }
    memset(dp,-1,sizeof(dp));
    int ans=shop(m,0);
    cout<<((ans<0)?"no solution":to_string(ans))<<endl;
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
