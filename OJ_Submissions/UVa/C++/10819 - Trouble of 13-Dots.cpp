#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000 + 4000 + 5;
int n, amount;
int dp[105][MAX];
pair<int,int> v[105]; 

int solve(int ind, int curr) {
    if (ind >= n) return 0;
    if (dp[ind][curr] != -1) return dp[ind][curr];  
    int limit = amount + (curr + v[ind].first > 2000 ? 200 : 0);
    int res = solve(ind + 1, curr);
    if (curr + v[ind].first <= limit) {
        res = max(res, v[ind].second + solve(ind + 1, curr + v[ind].first));
    }
    return dp[ind][curr] = res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    while (cin >> amount >> n) {
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        memset (dp, -1, sizeof(dp));
        sort (v, v + n);
        cout << solve(0, 0) << '\n';
    }
    
    return 0;
}