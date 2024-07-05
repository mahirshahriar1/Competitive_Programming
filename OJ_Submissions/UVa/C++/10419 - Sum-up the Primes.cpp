#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
vector<bool> isprime;
vector<int> prime;

void sieve()
{
    isprime.assign(MAXN + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i * i; j <= MAXN; j += i) {
            isprime[j] = false;
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (isprime[i]) prime.push_back(i);        
    }   
}

int sum, n;
int dp[62][1001][15];

int solve(int ind, int rsum, int rn) {
    if (rsum == 0 and rn == 0) return 1;
    if (ind >= (int) prime.size()) return 0;
    int &ret = dp[ind][rsum][rn];
    if (ret != -1) return ret;
    ret = 0;
    if (prime[ind] == 2) {
        if (rsum - 2 >= 0 and rn - 1 >= 0) {
            ret |= solve(ind + 1, rsum - 2, rn - 1);
        }
        ret |= solve(ind + 1, rsum, rn);
    }
    else { 
        if (rsum - 2 * prime[ind] >= 0 and rn - 2 >= 0) {
            ret |= solve(ind + 1, rsum - 2 * prime[ind], rn - 2);
        }
        if (rsum - prime[ind] >= 0 and rn - 1 >= 0) {
            ret |= solve(ind + 1, rsum - prime[ind], rn - 1);
        }
        ret |= solve(ind + 1, rsum, rn);
    }
    return ret;
}

vector<int> get_primes(int sum, int n) {
    vector<int> ans;
    for (int i = 0; i < (int) prime.size(); i++) {
        if (prime[i] == 2) {
            if (sum - 2 >= 0 and n - 1 >= 0 and solve(i + 1, sum - 2, n - 1)) {
                ans.push_back(2);
                sum -= 2;
                n--;
            }
        }
        else {
            if (sum - 2 * prime[i] >= 0 and n - 2 >= 0 and solve(i + 1, sum - 2 * prime[i], n - 2)) {
                ans.push_back(prime[i]);
                ans.push_back(prime[i]);
                sum -= 2 * prime[i];
                n -= 2;
            }
            else if (sum - prime[i] >= 0 and n - 1 >= 0 and solve(i + 1, sum - prime[i], n - 1)) {
                ans.push_back(prime[i]);
                sum -= prime[i];
                n--;
            }
        }
    }
    return ans;
}


int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    sieve();
    sort(prime.begin(), prime.end(), [](int a, int b) {
        return to_string(a) < to_string(b);
    });
    
    memset(dp, -1, sizeof dp);
    int tc = 1;
    while (cin >> sum >> n) {
        if (sum == 0 and n == 0) break;
        cout << "CASE " << tc++ << ":\n";
        bool possible = solve(0, sum, n);
        if (possible) {
            vector<int> ans = get_primes(sum, n);
            for (int i = 0; i < (int) ans.size(); i++) {
                cout << ans[i] << "+\n"[i == (int) ans.size() - 1];
            }
        }
        else {
            cout << "No Solution.\n";
        }
    }

    return 0;
}