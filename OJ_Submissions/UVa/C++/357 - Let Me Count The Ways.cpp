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

ll dp[7][30000+10];
ll func(ll ind , ll amount){
    if(amount==0) return 1;
    if(ind>=5) return 0;
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
    ll n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n){
        ll val=func(0,n);
        if(val==1){
            cout<<"There is only "<<val<<" way to produce "<<n<<" cents change.\n";
        }
        else    cout<<"There are "<<val<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}
