#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) v.begin(), v.end()
typedef long long ll;

const int mod = 1000000007;
int kas;

void solve() {

    cout << "Case " << ++kas << ": ";

    int n;
    cin >> n;
    vector <int> v(n);
    for (auto &x: v) cin >> x;
    sort (all(v));
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        ll val = v[i] - i;
      //  cout << val << endl;
        if (val < 0) {
            ans = 0;
            break;
       }
       ans = (ans * val) % mod;
    }
    ans %= mod;
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
