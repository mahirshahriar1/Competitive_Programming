#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps = 1e-9;


void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;

  if(a<=b)
    {
        int val1,corr;
        val1=(b-a)*y+x;
        corr=(2*(b-a)+1)*x;
        int ans=min(val1,corr);
        cout<<ans<<endl;
    }
    else
    {
        int val1,corr;
        val1=(a-b-1)*y+x;
        corr=(2*(a-b)-1)*x;
        int ans=min(val1,corr);
        cout<<ans<<endl;
    }
}


int main()
{
    fastio;

    solve();

    return 0;
}

