#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'

ll dp[101][11][(1 << 10) + 5];
ll n, m, tc;
int vis[101][11][(1 << 10) + 5];

ll solve(int row, int col, int mask) {
    if (row == n) return 1; 
    if (col == m) return solve(row + 1, 0, mask); 

    if (vis[row][col][mask] == tc) return dp[row][col][mask];
    vis[row][col][mask] = tc;
    ll &res = dp[row][col][mask];
    res = 0;
// mask is transitioned into the next row
// we change mask when we place a domino vertically
// as it affects the next row
   
    if ((mask & (1 << col)) == 0) {       
        if (col + 1 < m && (mask & (1 << (col + 1))) == 0) {
            res += solve(row, col + 2, mask);
        }
        if (row + 1 < n) {          
            res += solve(row, col + 1, mask | (1 << col));
        }
    }
    else {      
        // as we are not placing a domino vertically
        // we unset the bit for next row to be able to place one
        res += solve(row, col + 1, mask & ~(1 << col));
    }
       
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    while (cin >> n >> m)
    {
        ++tc;
        // cout << tc << ' ';
        if (m > n) swap(n, m); // n >= m
        // ensuring that m is always <= 10 as n * m <= 100
        // mask contains information about the current row
        // if jth bit is set then it means that the jth column is occupied
        // so (1 << 10) is enough to store the mask
        cout << solve(0, 0, 0) << endl;
    }

    return 0;
}