#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

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
        int n, x;
        cin >> n >> x;

        if (n % x != 0)
        {
            cout << -1 << endl;
            continue;
        }

        if (x == n)
        {
            cout << x << ' ';
            for (int i = 2; i <= n - 1; i++)
                cout << i << ' ';
            cout << 1 << endl;
            continue;
        }

        vector<int> v(n + 1, 0);
        for (int i = 0; i <= n; i++)
            v[i] = i;

        v[n]=1;
        v[1]=x;
        v[x] = n;
        for (int i = 2; i < n; i++)
        {
            if (i % x == 0 and n % i == 0)
            {
                swap(v[i], v[x]);
                x = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
