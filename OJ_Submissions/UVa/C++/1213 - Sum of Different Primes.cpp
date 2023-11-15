#include <bits/stdc++.h>
using namespace std;

vector<bool> isprime;
vector<int> primes;
const int MAXN = 1200;

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

int n, k;
long long dp[200][1200][15];

long long solve(int ind = primes.size() - 1, int sum = 0, int cnt = 0) { 
    if (ind < 0 or cnt >= k or sum >= n) {
        return (sum == n and cnt == k);
    }
    long long &res = dp[ind][sum][cnt];
    if (res != -1) return res;
    long long not_take = solve(ind - 1, sum, cnt);
    long long take = solve(ind - 1, sum + primes[ind], cnt + 1);
    return res = not_take + take;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    sieve();
    
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        memset(dp, -1, sizeof(dp));
        cout << solve() << "\n";
    }
    

    return 0;
}