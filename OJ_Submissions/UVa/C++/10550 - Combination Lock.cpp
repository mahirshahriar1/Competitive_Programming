#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int start, a, b, c;
    while (cin >> start >> a >> b >> c)
    {
        if (a == 0 && b == 0 && c == 0 && start == 0)
            break;
        // value decreases clockwise
        // value increases counter-clockwise

        int ans = 360 * 2;
        ans += a > start ? (start - a + 40) * 9 : (start - a) * 9;
        ans += 360;
        ans += b > a ? (b - a) * 9 : (b - a + 40) * 9;
        ans += c > b ? (b - c + 40) * 9 : (b - c) * 9;
        cout << ans << "\n";
    }
}
