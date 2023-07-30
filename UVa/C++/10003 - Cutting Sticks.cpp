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

int l;
int n;
int dp[55][55];
vector<int> cutpoint;
int func(int l,int r){   
    if(dp[l][r]!=-1) return dp[l][r];
    if(l+1==r) return dp[l][r]=0;

    int ans=INT_MAX;

    for(int i=l+1;i<r;i++){
        ans=min(ans,func(l,i)+func(i,r)+cutpoint[r]-cutpoint[l]);
    }
    return dp[l][r]=ans;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    while(cin>>l , l!=0){
        memset(dp,-1,sizeof(dp));
        cout<<"The minimum cutting is ";
       
        cin>>n;
        cutpoint.push_back(0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cutpoint.push_back(x);
        }
        cutpoint.push_back(l);
        cout<<func(0,n+1)<<'.'<<endl;
        cutpoint.clear();
    }

}
