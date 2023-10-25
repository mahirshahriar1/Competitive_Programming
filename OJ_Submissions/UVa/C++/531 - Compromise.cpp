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

int dp[110][110];
int lcs(vector<string> s1, vector<string> s2, int n, int m)
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
    freopen("output.txt", "w", stdout);
#endif

    vector<string> v1, v2;
    string s1, s2;
    int mx = -1;

    while (getline(cin, s1))
    {
        v1.clear();
        v2.clear();
        if (s1 == "#")
            break;
        else
        {
            stringstream ss(s1);
            while (ss >> s2)
                v1.push_back(s2);
            while (getline(cin, s1))
            {
                if (s1 == "#")
                    break;
                else
                {
                    stringstream ss(s1);
                    while (ss >> s2)
                        v1.push_back(s2);
                }
            }
        }

        while (getline(cin, s1))
        {
            if (s1 == "#")
                break;
            else
            {
                stringstream ss(s1);
                while (ss >> s2)
                    v2.push_back(s2);
            }
        }

        memset(dp, 0, sizeof(dp));
        lcs(v1, v2, v1.size(), v2.size());

        // for(int i=0;i<=v1.size();i++)
        // {
        //     for(int j=0;j<=v2.size();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }

        stack<string> ans;
        int i = v1.size(), j = v2.size();
        while (i > 0 && j > 0)
        {
            if (v1[i - 1] == v2[j - 1])
            {
                ans.push(v1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        while (!ans.empty())
        {
            cout << ans.top();
            if (ans.size() > 1)
                cout << " ";
            ans.pop();
        }
        cout << endl;


    }
}
