#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int kas=0;

void solve()
{
   int a,b;
   cin>>a>>b;
   cout<<"Case "<<++kas<<": "<<a+b<<endl;
}


int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;

}





