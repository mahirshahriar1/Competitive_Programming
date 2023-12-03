// Find the longest subarray with product of elements not divisible by x
#include <bits/stdc++.h>
using namespace std;


vector<bool> isprime;
vector<int> primes;
const int MAXN = 1e7 + 5;

void sieve()
{
    isprime.assign(MAXN + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (!isprime[i])
            continue;
        for (int j = i * i; j <= MAXN; j += i)
            isprime[j] = false;
    }
    for (int i = 2; i <= MAXN; i++)
        if (isprime[i])
            primes.push_back(i);
}

vector<pair<int, int>> prime_factorize(int n)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i])
            continue;
        res.emplace_back(primes[i], 0);
        while (n % primes[i] == 0)
        {
            n /= primes[i];
            res.back().second++;
        }
    }
    if (n != 1)
        res.emplace_back(n, 1);
    return res;
}

#define len(x) (int)(x).size()

void example3()
{

    vector<int> v = {2, 4, 5, 9, 19, 4, 8};
	int x = 2;
 
	map<int, int> mp, mpx;
 
	int not_valid = 0;
	auto pf1 = prime_factorize(x);
 
	for (auto [p, cnt] : pf1) {
		mpx[p] = cnt;
	}

	int ans = 0;
	int left = 0;
  
	for (int right = 0; right < len(v); right++)
	{
		auto pf = prime_factorize(v[right]);
 
		for (auto [p, cnt] : pf)
		{
			mp[p] += cnt;      
            if (mpx.count(p) == 0) continue;
			if (mp[p] >= mpx[p] && mp[p] - cnt < mpx[p]) {
				not_valid++;
			}
		}
 
		while (not_valid == len(mpx) && left < right) {
			auto pf = prime_factorize(v[left]);
            
			for (auto [p, cnt] : pf) {
				mp[p] -= cnt;
                if (mpx.count(p) == 0) continue;
				if (mp[p] < mpx[p] && mp[p] + cnt >= mpx[p])
				{
					not_valid--;
				}
			}
 
			left++;
		}         
     
		ans = max(ans, right - left+1);
	}

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        example3();      
    }

    return 0;
}