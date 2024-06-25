#include <bits/stdc++.h>
using namespace std;

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
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
		s_hash.resize(s.size() + 1);
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
	long long bwd_hash(int start, int end) {
		long long raw_val =
		    (s_hash[start] - (s_hash[end + 1] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}

};
vector<long long> HashedString::pow = {1};




int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    while (cin >> n , n != 0)
    {
        vector<pair<long long,string>> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            HashedString temp(s);
            v.push_back({temp.fwd_hash(0, s.size() - 1), s});
        }
        string s;
        cin >> s;
        HashedString hs(s);
        int len_str = s.size();
        int mx = 0;

        vector<int> cnt(n,0);
        for (int i = 0; i < n; ++i) {
            int len_pat =  v[i].second.size();
            for (int j = 0; j + len_pat - 1 < len_str; ++j) {
                // cout << hs.fwd_hash(j, j + len_pat - 1) << ' ' << v[i].first << '\n';
                if (hs.fwd_hash(j, j + len_pat - 1) == v[i].first)
                {
                    cnt[i]++;
                    mx = max(mx,  cnt[i]);
                }
            }
        }
        cout << mx << '\n';
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == mx) {
                cout << v[i].second << '\n';
            }
        }

    }

    return 0;
}