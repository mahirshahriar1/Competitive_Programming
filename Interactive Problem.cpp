// Codeforces https://codeforces.com/contest/1807/problem/E


#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<ll> presum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i - 1] + v[i];
    }
    int l = 1, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << "? " << mid - l + 1 << " ";
        for (int i = l; i <= mid; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
        ll sum = 0;
        cin >> sum;
        ll presum1 = presum[mid] - presum[l - 1];
        if (sum == presum1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << "! " << ans << endl;
    cout.flush();
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
}
