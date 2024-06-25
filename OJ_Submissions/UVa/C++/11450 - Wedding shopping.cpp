#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const int mod = 1e9 + 7;

int m, c, price[25][25];
int dp[210][25];

int shop(int money, int g)
{
    if (money > m) return -1;
    if (g == c) return money;
    int &ans = dp[money][g];
    if (ans != -1) return ans;
    
    for (int x = 1; x <= price[g][0]; x++)
        ans = max(ans, shop(money + price[g][x], g + 1));
    return ans;
}

void solve()
{
    cin >> m >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> price[i][0];
        for (int j = 1; j <= price[i][0]; j++)
            cin >> price[i][j];
    }
    memset(dp, -1, sizeof(dp));
    int ans = shop(0, 0);
    cout << ((ans < 0) ? "no solution" : to_string(ans)) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
