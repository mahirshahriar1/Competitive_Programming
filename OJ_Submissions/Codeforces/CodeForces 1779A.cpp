#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L = 0, R = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            L++;
        if (s[i] == 'R')
            R++;
        if (L and R)
            break;
    }

    if (!L || !R)
    {
        cout << -1 << endl;
        return;
    }
    bool right = false, left = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R' and !left)
        {
            cout << 0 << endl;
            return;
        }
        else if (s[i] == 'L')
            left = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L' and i + 1 < n and s[i + 1] == 'R')
        {
            cout << i + 1 << endl;
            return;
        }
        else if (s[i] == 'L' and s[i - 1] == 'R')
        {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }

    return 0;
}
