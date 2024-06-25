#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

ll dp[15][(1 << 15) + 2][2][2];
int arr[15][15], n;

ll solve(int i, int mask, bool f1, bool f2)
{
    if (i == n)
        return f1 | f2;
    ll &ret = dp[i][mask][f1][f2];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j))) {
            ret += solve(i + 1, mask | (1 << j), f1 & (arr[i][j] != 0), f2 | (arr[i][j] == 2));
        }
    }
    return ret;
}

void run_case(const int &tc)
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    cout << "Case " << tc << ": " << solve(0, 0, 1, 0) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        run_case(tc);        
    }

    return 0;
}