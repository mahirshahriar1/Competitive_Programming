#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) v.begin(), v.end()
typedef long long ll;

int kas;
bool comp (const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.second > b.second;
}

void solve() {
    cout << "Case " << ++kas << ": ";

    ll n;
    cin >> n;
    vector <pair<ll,ll>> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    sort(all(v),comp);
    
    ll ans = 0;
    ll mn = INT_MAX;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        mn = min (mn, v[i].second);
        cnt += v[i].first;
        ans = max(ans, (cnt * mn));
    }
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
