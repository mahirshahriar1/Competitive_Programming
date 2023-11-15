#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

unordered_map<ll, ll> dp;

ll solve(ll n)
{
    if (n <= 2) return 0;
    if (dp.count(n)) return dp[n];
    return dp[n] = (n - 1) / 2 + solve((n - 1) / 2) + solve(n / 2);    
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        ll n;
        cin >> n;
        cout << "Case " << tc << ": " << solve(n) << endl;       
    }

    return 0;
}