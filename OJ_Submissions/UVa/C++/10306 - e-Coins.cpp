#include <bits/stdc++.h>
using namespace std;

int n, sum;
int dp[42][310][310];

int solve(int ind, int x, int y, vector<pair<int,int>> &v) {
    if ((x * x) + (y * y) == (sum * sum)) return 0;
    if ((x * x) + (y * y) > (sum * sum)) return 1e9;
    if (ind == n) return 1e9;
    int &ret = dp[ind][x][y];
    if (ret != -1) return ret;
    ret = 1e9;
    ret = min(ret, solve(ind, x + v[ind].first, y + v[ind].second, v) + 1);
    ret = min(ret, solve(ind + 1, x, y, v));
    return ret;
}   

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n >> sum;
        vector<pair<int, int>> v(n);
        for (auto &x: v) cin >> x.first >> x.second;
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0, 0, v);
        cout << (res >= 1e9 ? "not possible" : to_string(res)) << "\n";
    }
    
    return 0;
}