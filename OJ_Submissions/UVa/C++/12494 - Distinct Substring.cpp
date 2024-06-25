#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int t;
	cin >> t;
	
	while (t--) {
		unordered_set<string> st;
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			for (int j = 1; j <= s.size() - i; j++) {
				auto temp = s.substr(i, j);
				string mn = temp;
				for (int k = 0; k < temp.size(); k++) {
					temp = temp[j - 1] + temp;
					temp.pop_back();
					mn = min(mn, temp);
				}
				st.insert(mn);
			}
		}		
		cout << st.size() << endl;
	}

	return 0;
}