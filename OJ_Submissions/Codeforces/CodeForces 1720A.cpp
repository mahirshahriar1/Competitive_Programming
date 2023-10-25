#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

void solve()
{

   ll a,b,c,d;
   cin>>a>>b>>c>>d;

   ll x=a*d;
   ll y=b*c;


   if(x==y)
    cout<<0<<endl;
    else if(x==0||y==0)
        cout<<1<<endl;
   else if(x%y==0||y%x==0)
    cout<<1<<endl;
   else
    cout<<2<<endl;

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
