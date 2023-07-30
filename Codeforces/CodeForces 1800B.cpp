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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char, ll> up;
        map<char, ll> down;

        for (ll i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                up[s[i]]++;
            }
            else
            {
                down[s[i]]++;
            }
        }
        ll ans = 0;
        for (auto x : up)
        {
            ans += min(x.second, down[tolower(x.first)]);
        }

        ll cnt = 0;
        bool a=false,b=false;
        for (auto x : up)
        {          
            cnt += (abs(x.second - down[tolower(x.first)])) / 2;           
            if(cnt>0){
                a=true;
            }
        }
        ll check=cnt;
        for(auto x:down)
        {
            cnt += (abs(x.second - up[toupper(x.first)])) / 2;
            if(cnt>check){
                b=true;
            }
        }
        if(a and b){
            cnt=min(cnt,cnt-check);
        }
   
        cout << ans + min(cnt, k) << endl;
    }
}
