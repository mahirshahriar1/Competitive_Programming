#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    if (n == 3)
    {
        cout << "NO" << endl;
        return;
    }
    else if (n % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2)
        {
            cout << "-1 1 ";
        }
        cout << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 1; i < n; i += 2)
        {
            cout << 1 - n / 2 << ' ' << n / 2 << ' ';
        }
        cout << 1 - n / 2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }

    return 0;
}
