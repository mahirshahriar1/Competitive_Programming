#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

void solve()
{
    char arr[8][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            cin>>arr[i][j];
    }

    for(int i=0; i<8; i++)
    {
        int cnt=0;
        for(int j=0; j<8; j++)
        {
            if(arr[i][j]=='R')
            {
                cnt++;
            }
        }

        if(cnt==8)
        {
            cout<<'R'<<endl;
            return;
        }
    }
    cout<<'B'<<endl;


}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);
#endif

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


}

