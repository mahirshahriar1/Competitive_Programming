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

int dp[25][25];
int n;
vector<int> v;

#define inf INT_MAX

int func(int cnt,int pos){    
    if(pos==n){  
        return cnt;
    }else if(cnt>=n){
        return inf;
    }else if(dp[cnt][pos]!=-1){
        return dp[cnt][pos];
    }

    int move1=pos+1;
    int move2=v[pos]+pos;

    int ans=inf;
    if(move2>=0 && move2<=n){
        ans=min(ans,func(cnt+1,move2));
    }
    ans=min(ans,func(cnt+1,move1));
    
    return dp[cnt][pos]=ans;
     
}

void solve(){
    memset(dp,-1,sizeof(dp));
    v.clear();
    
    cin>>n;
    v.resize(n);
    
    for(auto &x:v) cin>>x;
    
    int res=func(0,0);

    if(res==inf){
        cout<<-1<<endl;
    }    
    else{
        cout<<res<<endl;
    }
    
}

int main(){
    fastio  


    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
