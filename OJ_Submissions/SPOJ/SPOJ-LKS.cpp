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

//space Optimized
int KnapSack(int val[], int wt[], int n, int W)
{ 

    int dp[W + 1];
   
    memset(dp, 0, sizeof(dp));
 
    for (int i = 0; i < n; i++)       
        for (int j = W; j >= wt[i]; j--)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
    
    return dp[W];
}


int solve(int i,int max_size){
    if(i>=n) return 0;

    if(dp[i][max_size]!=-1) return dp[i][max_size];

    int val1=0,val2=0;

    if(max_size-sz[i]>=0){
        val1=value[i]+solve(i+1,max_size-sz[i]);
    }
    val2=solve(i+1,max_size);

    return dp[i][max_size]=max(val1,val2);
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, w;
    cin >> w >> n;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
        cin >> val[i] >> wt[i];
    cout << KnapSack(val, wt, n, w) << endl;
}
