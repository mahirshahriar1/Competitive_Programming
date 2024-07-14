// https://atcoder.jp/contests/abc336/tasks/abc336_e

// The digit sum of a positive integer n is defined as the sum of the digits in the decimal notation of n. 
// For example, the digit sum of 2024 is 2+0+2+4=8.
//  A positive integer n is called a good integer when n is divisible by its digit sum. 
// For example, 2024 is a good integer because it is divisible by its digit sum of 8. 
// You are given a positive integer N. How many good integers are less than or equal to N?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[15][2][130][130];
ll go(string& R, int N, int sum, bool tight = true, int ind = 0, int curr = 0, int rem = 0) {
    if (ind == N) return (rem == 0 && curr == sum);
        
    ll &ans = dp[ind][tight][curr][rem];
    if (ans != -1) return ans;
    ans = 0;
    int ed = tight ? R[ind] - '0' : 9;
    for (int j = 0; j <= ed; ++j) {
        ans += go(R, N, sum, (tight && j == ed), ind + 1, curr + j, (rem * 10 + j) % sum);
    }
    return ans;
}

void run_case(int tc) {
    ll n;
    cin >> n;
    string R = to_string(n);

    ll cnt = 0;
    for (int i = 1; i <= 130; ++i) {
        memset(dp, -1, sizeof dp);
        cnt += go(R, (int) R.length(), i);
    }
    cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    run_case(tc);
  }


  return 0;
}