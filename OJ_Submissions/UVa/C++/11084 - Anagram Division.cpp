#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

ll dp[(1 << 10) + 10][10000 + 10], d;
string s;

ll solve(int mask, int rem) {
    if (mask == (1 << s.size()) - 1) {
        return rem == 0;
    }
    ll &ret = dp[mask][rem];
    if (ret != -1) return ret;

    ret = 0;
    set<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (mask & (1 << i)) continue;
        if (st.count(s[i])) continue;  
        st.insert(s[i]);
        int digit = s[i] - '0';
        ret += solve(mask | (1 << i), (rem * 10 + digit) % d);
    }
    return ret;
}


int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        cin >> s >> d;
        memset(dp, -1, sizeof dp);
        cout <<  solve(0, 0) << endl;   
    }

    return 0;
}