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

int dp[105][105];

int lcs(vector<int> s1, vector<int> s2, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
   fastio  
   #ifndef ONLINE_JUDGE  
          freopen("input.txt", "r", stdin); 
          freopen("output.txt", "w",stdout);
   #endif

    int a,b;
    int kas=1;
    bool f=0;
    while(cin>>a>>b)
    {
        if(f)
            cout<<endl;
        if(a==0 && b==0)
            break;
        vector<int> v1(a),v2(b);
        takeInput(v1);
        takeInput(v2);
        memset(dp,-1,sizeof(dp));
        int ans=lcs(v1,v2,a,b);
        
        cout<<"Twin Towers #"<<kas++<<endl;
        cout<<"Number of Tiles : "<<ans<<endl;
        f=1;
    }

}
