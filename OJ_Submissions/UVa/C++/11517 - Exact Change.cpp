#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int n, sum;

int solve(int ind, int curr, vector<int> &v, vector<vector<int>> &dp) {
    if (ind >= n) return (curr >= sum ? 0 : inf);
    if (curr >= sum) return 0;
    int &ret = dp[ind][curr];
    if (ret != -1) return ret;
    ret = min(solve(ind + 1, curr, v, dp), solve(ind + 1, curr + v[ind], v, dp) + v[ind]);
    return ret;
}

int get(int ind, int curr, int amount, vector<int> &v, vector<vector<int>> &dp) {
    if (ind >= n) return (curr == amount ? 0 : inf);
    if (curr >= amount) return curr == amount ? 0 : inf;
    int &ret = dp[ind][curr];
    if (ret != -1) return ret;
    ret = min(1 + get(ind + 1, curr + v[ind], amount, v, dp), get(ind + 1, curr, amount, v, dp));
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> sum >> n;      
        vector<int> v(n);
        for (auto &x: v) cin >> x;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        int mn_amount = solve(0, 0, v, dp);

        dp.assign(n, vector<int>(mn_amount + 1, -1));  
        int mn_cnt = get(0, 0, mn_amount, v, dp);

        cout << mn_amount << ' ' << mn_cnt << '\n';
    }
    
    return 0;
}