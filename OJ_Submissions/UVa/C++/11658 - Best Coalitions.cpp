#include <bits/stdc++.h>
using namespace std;

int n, x;
int dp[105][5005];

int solve(int ind, int w, vector<int> &v) {
    if (w > 5000) return w; 
    if (ind == n) return 1e9; 
    if (dp[ind][w] != -1) return dp[ind][w];
    int res = 1e9;
    if (ind == x - 1) res = min(res, solve(ind + 1, w, v));
    else {
        res = min(res, solve(ind + 1, w + v[ind], v));
        res = min(res, solve(ind + 1, w, v));
    }
    return dp[ind][w] = res;    
}

int32_t main()
{
    while(scanf("%d %d", &n, &x) != EOF) {
        if (n == 0 and x == 0) break;
        vector<int> v;        
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d.%d", &a, &b);
            v.push_back(a * 100 + b);
        }
        // assert(accumulate(v.begin(), v.end(), 0) == 10000);
       
        int res = solve(0, v[x - 1], v);
        double ans = ((1.0) * v[x - 1])/ (1.0 * res) * 100.0;
        printf("%.2lf\n", ans);
    }
    
    return 0;
}