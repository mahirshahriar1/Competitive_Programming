#include <bits/stdc++.h>
using namespace std;

string s;
int dp[1010][1010];

int solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    auto &ret = dp[l][r];
    if (ret != -1) return ret;
    if (l + 1 == r) return ret = (s[l] == s[r] ? 2 : 1);
    else if (s[l] == s[r]) return ret = 2 + solve(l + 1, r - 1);
    return ret = max(solve(l + 1, r), solve(l, r - 1));
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    cin.ignore();
    for (int tc = 1; tc <= t; ++tc) {    
        getline(cin, s);
        memset(dp, -1, sizeof dp);       
        cout << solve(0, s.size() - 1) << '\n';
    }

    return 0;
}