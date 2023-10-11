"cpp": "cd $dir && g++ -std=c++20 -DLOCAL \"-Wl,--stack=2147483648\" '$fileName' -o '$fileNameWithoutExt' && Get-Content 'C:\\Users\\Mahir\\Desktop\\contest\\contestcf\\input.txt' | & '$dir$fileNameWithoutExt.exe' | Set-Content 'C:\\Users\\Mahir\\Desktop\\contest\\contestcf\\output.txt' && del '$dir$fileNameWithoutExt.exe'",


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define endl '\n'
#define all(v) v.begin(), v.end()
#define print(v) for(auto& i:v) cout<<i<<" "; cout<<endl;
#define len(v) (int)v.size()

template<typename T>
inline void operator>>(istream& istream, vector<T>& v){for (T& i : v) {cin >> i;}}

// #define cerr if(false) cerr

void solve([[maybe_unused]]const int &tc)
{
    cout << "Case " << tc << ": ";
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<int> v(n);
    cin >> v;
    sort (v.begin(), v.end());

    ll cnt = 0;
    for (int i = 0; i < n; ++i) {   
        ll val1 = a - v[i];
        ll val2 = b - v[i];      
        debug (val1, val2, v[i]);
        auto it1 = lower_bound(v.begin() + i + 1, v.end(), val1);
        auto it2 = upper_bound(v.begin() + i + 1, v.end(), val2);
        // cout << (it2 -v.begin()) << " " << (it1 - v.begin()) << endl;
        cnt += (it2 - it1);
    }
    cout << cnt << endl;
   
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {    
        debug (tc);   
        solve(tc); 
        debug ("------------------");
    }

    return 0;
}
