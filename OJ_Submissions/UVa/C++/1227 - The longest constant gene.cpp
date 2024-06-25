#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int sz = 1e6 + 5;
const ll base = 43;
const ll mod = 1e9 + 7;
string s[10];
ll num, f_hash[10][sz], base_pow[sz];
int mn;

void build_pow() {
    base_pow[0] = 1;
    for (int i = 1; i < sz; ++i) {
        base_pow[i] = (base_pow[i - 1] * base) % mod;
    }
}

void build_hash(int pos) {
    int n = s[pos].size();
    for (int i = 0; i < n; ++i) {
        f_hash[pos][i + 1] = (f_hash[pos][i] * base + s[pos][i]) % mod;
    }
}

ll foward_hash(int pos, int i, int j) {
    ll hash = f_hash[pos][j + 1] - (f_hash[pos][i] * base_pow[j - i + 1] % mod);
    return hash < 0 ? hash + mod : hash;
}

bool ok(int len) {
    gp_hash_table<ll, null_type> st1, st2;
    for (int i = 0; i < num; ++i) {
        st2.clear();
        int n = s[i].size();
        for (int j = 0; j + len - 1 < n; ++j) {
            ll h = foward_hash(i, j, j + len - 1);
            if (i == 0) {
                st1.insert(h);
            } else if (st1.find(h) != st1.end()) {
                st2.insert(h);
            }
        }
        if (i) {
            st1 = st2;
        }
    }
    return (st1.size() > 0);
}

void run_case(const int &tc = 0) {
    mn = INT_MAX;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> s[i];
        build_hash(i);
        mn = min(mn, (int)s[i].size());
    }
    ll l = 1, r = mn, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    build_pow();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
        run_case(t);
    }
    return 0;
}
