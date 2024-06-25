#include <bits/stdc++.h>
using namespace std;

const int N = 60;
int dp[N][N][N][N], vis[N][N][N][N], tc = 0;
string a, b;

int solve(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return 0;
    int &ret = dp[l1][r1][l2][r2];
    if (vis[l1][r1][l2][r2] == tc) return ret;
    // if left and right pointers are same, then we have only one element
    // so we can directly compare them
    if (l1 == r1 && l2 == r2) return a[l1] == b[l2];
    vis[l1][r1][l2][r2] = tc;
    ret = 0;
    
    // we can either skip a character from a or b
    // 4 possibilities
    ret = max(ret, solve(l1 + 1, r1, l2, r2));
    ret = max(ret, solve(l1, r1 - 1, l2, r2));
    ret = max(ret, solve(l1, r1, l2 + 1, r2));
    ret = max(ret, solve(l1, r1, l2, r2 - 1));
    if (a[l1] == a[r1] and b[l2] == b[r2] and a[l1] == b[l2] and !(l1 == r1 or l2 == r2)) {
        ret = max(ret, 2 + solve(l1 + 1, r1 - 1, l2 + 1, r2 - 1));
    }
    
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (tc = 1; tc <= t; ++tc) {   
        cin >> a >> b;
        cout << "Case " << tc << ": " << solve(0, a.size() - 1, 0, b.size() - 1) << '\n';
    }

    return 0;
}