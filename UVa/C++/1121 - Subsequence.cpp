#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    int64_t sum;
    
    while(cin >> n >> sum) {
        vector<int64_t> v(n);
        for (auto &x : v) cin >> x;
        partial_sum(v.begin(), v.end(), v.begin());
        int ans = INT_MAX;
        int l = 0, r = 0;
        while (r < n) {
            int64_t curr = v[r] - (l ? v[l - 1] : 0);
            if (curr >= sum) {
                ans = min (ans, r - l + 1);
            }
            if (curr < sum) {
                r++;
            } else {
                l++;
            }
        }
        cout << (ans == INT_MAX ? 0 : ans) << endl;
    }

    return 0;
}