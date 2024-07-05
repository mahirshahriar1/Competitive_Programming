#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int r, c, h;
        cin >> c >> r >> h;
        vector<vector<int>> a(r + 1, vector<int>(c + 1));
        for (int i = 1; i <= c; ++i) {
            int k; cin >> k;
            for (int j = 0; j < k; ++j) {
                int x; cin >> x;
                a[x][i] += 1;
            }
        }
        vector<vector<int64_t>> dp(r + 1, vector<int64_t>(c + 1, 0LL));
        vector<int64_t> mx_row(r + 1, 0);
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                if (i - h >= 0) {
                    dp[i][j] = max(dp[i][j], mx_row[i - h] + a[i][j]);
                }
            }
            for (int j = 1; j <= c; ++j) {
                mx_row[i] = max(mx_row[i], dp[i][j]);
            }
        }
        cout << *max_element(dp[r].begin(), dp[r].end()) << '\n';
    }

    return 0;
}