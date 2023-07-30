#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v)  \
    for (auto &x : v) \
        cin >> x;
#define precision(n) fixed << setprecision(n)
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define range(v) v.begin(), v.end()
typedef long long int ll;
const double eps = 1e-9;

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string ss;
    cin >> ss;
    string s = " " + ss;
    char str[n];

    if (n % 2)
    {
        str[n / 2] = s[1];
        int l = 1, r = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                str[n / 2 - l] = s[i];
                l++;
            }
            else
            {
                str[n / 2 + r] = s[i];
                r++;
            }
        }
    }else{
        str[n / 2 - 1] = s[1];
        int l = 2, r = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                str[n / 2 - l] = s[i];                
                l++;                
            }
            else
            {
                str[n / 2 + r] = s[i];    
                r++;
            }
        }

    }
    for(auto x:str){
        cout<<x;
    }
    cout<<endl;

    return 0;
}
