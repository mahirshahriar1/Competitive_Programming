// Lightoj - How Many Zeroes?
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define endl '\n'

ll num[20];
ll dp[20][20][2][2];

ll solve(int pos, ll val = 0, bool isZero = true, bool tight = true) {
  if (pos < 0) {
    return isZero == 1? 1: val;
  }
  if (dp[pos][val][isZero][tight] != -1) {
    return dp[pos][val][isZero][tight];
  }
  ll ub = tight ? num[pos] : 9;

  ll ret = 0;
  for (int i = 0; i <= ub; ++i) {
    if (isZero) {
      ret += solve(pos - 1,  0, (i == 0), tight & (i == ub) );
    } else {
      ret += solve(pos - 1, val + (i == 0), isZero, tight & (i == ub));
    }
  }
  return dp[pos][val][isZero][tight] = ret;
}

void run_case(int tc) {
  cout << "Case " << tc << ": ";
  ll m, n;
  cin >> m >> n;

  auto mm = m;
  auto nn = n;
  --mm;
  int i = 0;
  memset(dp, -1, sizeof(dp));

  while (mm) num[i++] = mm % 10, mm /= 10;
  auto res1 =  solve(i - 1);

  memset(dp, -1, sizeof(dp));
  i = 0;
  while (nn) num[i++] = nn % 10, nn /= 10;
  auto res2 = solve(i - 1);

  cout << res2 - res1 << endl;

}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    run_case(tc);
  }

  return 0;
}

