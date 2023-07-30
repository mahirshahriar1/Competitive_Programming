#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

vector<pair<ll, ll>> pfactors_pair(ll n)
{
    vector<pair<ll, ll>> result;
    for (ll p = 2; p * p <= n; p++)
    {
        ll cnt = 0;
        if (n % p)
            continue;
        while (n % p == 0)
        {
            n /= p;
            ++cnt;
        }
        result.push_back({p, cnt});
    }
    if (n > 1)
        result.push_back({n, 1});
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll k;
    cin >> k;

    vector<pair<ll, ll>> factors = pfactors_pair(k);

    ll ans = 1;

    for (auto& x : factors)
    {
        ll prime = x.first, occ = x.second;

        ll itr = prime;
        while (true)
        {
            ll temp = itr;

            while (temp % prime == 0)
            {
                temp /= prime;
                occ--;
            }

            if (occ <= 0)
                break;
            itr += prime;
        }
        ans = max(ans, itr);
    }
    cout << ans << endl;
}
