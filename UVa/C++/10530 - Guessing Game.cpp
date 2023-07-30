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

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    int low = 100, high = -1;
    map<int,int> hi,lo;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        string s;
        cin >> s;
        cin >> s;

        if (s == "high")
        {
           hi[n]++;
        }
        else if (s == "low")
        {
            lo[n]++;
        }
        else
        {
            bool found=false;
            for(auto x:hi){
                if(n>=x.first){
                    found=true;
                    break;
                }
            }
            if(!found){
                for(auto x:lo)
                {
                    if(n<=x.first){
                        found=true;
                        break;
                    }
                }
            }
            cout<<(found?"Stan is dishonest":"Stan may be honest")<<endl;
           
            hi.clear();
            lo.clear();
        }
    }

    return 0;
}
