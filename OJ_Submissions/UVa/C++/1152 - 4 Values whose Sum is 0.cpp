#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define endl '\n'


int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int t, tc = 0;
	cin >> t;

	while (t--) {
		if (tc != 0) {
			cout << endl;
		}
		tc++;
		int n, cnt = 0;
		cin >> n;
		vector<array<int, 4>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
		}
		
		gp_hash_table<int, int> mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; ++j) {
				mp[v[i][0] + v[j][1]]++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; ++j) {
				cnt += mp[-(v[i][2] + v[j][3])];
			}
		}
		cout << cnt << endl;
	}

	return 0;
}