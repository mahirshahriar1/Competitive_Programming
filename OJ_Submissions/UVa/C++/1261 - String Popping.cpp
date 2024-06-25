#include <bits/stdc++.h>
using namespace std;


map<string, int> dp;

int ok(string &s) {
    if ((int)s.size() == 0) return 1;
    if (dp.count(s)) return dp[s];
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) ++j;
        auto t = s;
        if (j - i >= 2) {
            t = s.substr(0, i) + s.substr(j);
            ret |= ok(t);
        }
        i = j - 1;
    }
    return dp[s] = ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {   
        string s;
        cin >> s;
        dp.clear();
        cout << (ok(s) ? 1 : 0) << '\n';
    }

    return 0;
}