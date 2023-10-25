#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    bool flag = false;
    for (int i = 0; i <= 9; i++)
    {
        a *= 10;
        a += i;
        if (a % b == 0)
        {
            flag = true;
            break;
        }
        a /= 10;
    }
    if (flag)
    {
        cout << a;
        n--;
        while (n--)
            cout << 0;
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}
