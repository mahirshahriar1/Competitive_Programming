#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MOD = 1000000;

int dp[105][105];
int solve(int n, int k)
{
    int &res = dp[n][k];
    if (res != -1)
        return res;
    if (k == 1)
        return res = 1;

    res = 0;
    for (int i = 0; i <= n; i++)
    {
        res = (res + solve(n - i, k - 1)) % MOD;
    }
    return res;
}

void dpSolution()
{
    int n, k;

    while (cin >> n >> k && n)
    {
        memset(dp, -1, sizeof(dp));
        cout << solve(n, k) << endl;
    }
}

void ncrSolution()
{
    long long c[202][202];

    for (int i = 0; i < 202; i++)
        c[i][0] = 1;

    for (int i = 1; i < 202; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;

    int n, k;
    while (cin >> n >> k && n)
        cout << c[n + k - 1][k - 1] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // ncrSolution();
    dpSolution();

    return 0;
}
