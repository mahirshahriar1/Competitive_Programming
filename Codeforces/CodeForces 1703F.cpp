#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define range(v) v.begin(),v.end()
typedef long long int ll;


void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> arr;

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] >= i)
            continue;
        ans += (ll)(lower_bound(range(arr), v[i]) - arr.begin());
       // cout << i << ' ' << v[i] << ' ' << ans << endl;
        arr.push_back(i);
    }
    cout << ans << endl;
}

int main()
{

    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
