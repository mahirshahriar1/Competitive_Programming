#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;


// substring occurence
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
 
    int lookup[m + 1][n + 1] = { { 0 } };
 
    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1]%mod +
                               lookup[i - 1][j]%mod;
                 
            else
                lookup[i][j] = lookup[i - 1][j]%mod;
        }
    }
 
    return lookup[m][n]%mod;
}

int main()
{
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    string a;
    cin>>a;
    string s="chokudai";

    ll sz=a.size();

    ll dp[sz+1][10]={{0}};

     for (int i = 0; i <= 10; ++i)
        dp[0][i] = 0;
 
    for (int i = 0; i <= sz; ++i)
        dp[i][0] = 1;

    for(int i=1;i<=sz;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(a[i-1]!=s[j-1]){
                dp[i][j]=dp[i-1][j]%mod;
            }
            else{
                dp[i][j]=dp[i-1][j]%mod+dp[i-1][j-1]%mod;
            }
        }
    }
    cout<<dp[sz][8]%mod<<endl;
   

}
