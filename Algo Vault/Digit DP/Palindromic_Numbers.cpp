// LightOJ - 1205 

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[20], dp[20][20][2][2], tmp[20];

ll solve(int len, int pos, bool leading_zero, bool is_small)
{
    if (pos == 0)
        return 1;
    if (dp[len][pos][leading_zero][is_small] != -1)
        return dp[len][pos][leading_zero][is_small];
    ll ret = 0, tight = is_small ? 9 : arr[pos];

    for (int dig = 0; dig <= tight; ++dig)
    {
        tmp[pos] = dig;
        if (leading_zero and dig == 0)
        {
            ret += solve(len - 1, pos - 1, 1, 1);
        }
        else if (pos > len / 2 or tmp[pos] == tmp[len - pos + 1])
        {
            ret += solve(len, pos - 1, 0, is_small | dig < tight);
        }
    }
    return dp[len][pos][leading_zero][is_small] = ret;
}

ll fun(ll x)
{
    int len = 0;
    while (x)
    {
        arr[++len] = x % 10;
        x /= 10;
    }
    // for (int i = 1; i <= len; ++i) cout << arr[i];  cout << "\n";

    memset(dp, -1, sizeof(dp));
    auto ret = solve(len, len, 1, 0);
    return ret;
}

void run_case(const int &tc)
{
    ll x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    // cout << fun(y) << " " << fun(x - 1) << "\n";
    cout << "Case " << tc << ": " << fun(y) - fun(x - 1) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        run_case(tc);
    }

    return 0;
}
