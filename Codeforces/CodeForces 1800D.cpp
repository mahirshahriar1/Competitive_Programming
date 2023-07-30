#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll test;
    cin >> test;

    for (ll testt = 1; testt <= test; testt++)
    {
        ll n;
        string s;
        cin >> n >> s;

        ll cnt = 0;
        string temp = "";
        for (int i = 0; i < n - 1; i++)
        {
            string tmp2 = s.substr(i, 2);
            sort(tmp2.begin(), tmp2.end());
            if (tmp2 != temp)
            {
                cnt++;
            }
            temp = tmp2;
            sort(temp.begin(), temp.end());
        }
        cout << cnt << endl;
    }
}
