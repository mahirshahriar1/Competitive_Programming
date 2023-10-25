#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v)  \
    for (auto &x : v) \
        cin >> x;
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define range(v) v.begin(), v.end()
typedef long long int ll;

const double eps = 1e-9;
const int mod = 1e9 + 7;

bool isPossible(vector<ll> v, ll sum, ll n)
{
    ll dp[sum + 1];

    dp[0] = 1;

    for (ll i = 0; i < n; i++)
    {

        for (ll j = sum; j >= v[i]; j--)
        {
            if (dp[j - v[i]] == 1)
                dp[j] = 1;
        }
    }

    if (dp[sum] == 1)
        return true;

    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    takeInput(v);

    sort(range(v));

    if(n==1 and v[0]!=1){
        cout<<"NO"<<endl;
        return;
    }
   
    if (n>=2 and (v[0] != 1 or v[1] != 1))
    {        
        cout << "NO" << endl;
        return;
    }
    ll sum=2;
    for (int i = 2; i < n; i++)
    {
        if(v[i]>sum){
            cout<<"NO"<<endl;
            return;
        }
        sum+=v[i];
    }
    cout << "YES" << endl;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
