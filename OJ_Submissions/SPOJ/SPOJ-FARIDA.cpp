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

int kas;
ll dp[(int)1e4+10];
int n;
ll mons[(int)1e4+10];

ll solve(int pos){
    if(pos>=n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    return dp[pos]=max(solve(pos+1),solve(pos+2)+mons[pos]);
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
        cin>>n;
        for(int i=0;i<n;i++)        
            cin>>mons[i];        

        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++kas<<": "<<solve(0)<<endl;
    }

}
