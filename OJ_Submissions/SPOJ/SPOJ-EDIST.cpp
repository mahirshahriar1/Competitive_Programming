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



// int editDistance(string s1, string s2, int m, int n)
// {
//     if (m == 0)
//         return n;
//     if (n == 0)
//         return m;
//     if (s1[m - 1] == s2[n - 1])
//         return editDistance(s1, s2, m - 1, n - 1);

//     int insert = editDistance(s1, s2, m, n - 1);
//     int remove = editDistance(s1, s2, m - 1, n);
//     int replace = editDistance(s1, s2, m - 1, n - 1);
//     return 1 + min({insert, remove, replace});
// }


int editDistance(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else{
                int insert = dp[i][j - 1];
                int remove = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({insert, remove, replace});
            }
        }
    }
    return dp[m][n];
}

void solve()
{
    string a, b;
    cin >> a >> b;
    int m = a.size(), n = b.size();
    cout << editDistance(a, b, m, n) << endl;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
