#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;
	static const long long B = 9973;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;
	vector<long long> s_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1, 0) {
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
		s_hash.resize(s.size() + 1, 0);
        s_hash[s.size()] = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            s_hash[i] = ((s_hash[i + 1] * B) % M + s[i]) % M;
        }
	}

	long long fwd_hash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
    long long rev_hash(int start, int end) {
        long long raw_val =
            (s_hash[start] - (s_hash[end + 1] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<long long> HashedString::pow = {1};

void solve()
{
	string s;
	cin >> s;
	HashedString hs(s);

	auto check = [&](int mid) {
		int n = s.size();
		long long target_hash = hs.fwd_hash(0, mid - 1);
		for (int i = 0; i + mid - 1 < n; ++i) {
			if (target_hash == hs.rev_hash(i, i + mid - 1)) {
				return true;
			}
		}
		return false;
	};


	int low = 0, high = s.size(), res = 0;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			res = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}	
	string ans = s.substr(0, res);
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int t = 1;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {    
		solve();        
	}

	return 0;
}