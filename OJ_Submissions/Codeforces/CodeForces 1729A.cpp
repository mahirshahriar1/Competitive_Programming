#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

void solve()
{

    int a,b,c;
    cin>>a>>b>>c;


    int val1=abs(c-b)+c;
    if(a<val1)
        cout<<1<<endl;
    else if(val1<a)
        cout<<2<<endl;
    else
        cout<<3<<endl;


}


int main()
{
    fastio;

    int t,kas=0;
    cin>>t;
    while(t--)
    {
        solve();
   }


    return 0;
}
