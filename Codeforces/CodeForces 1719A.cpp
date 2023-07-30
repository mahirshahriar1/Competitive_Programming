#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


void solve()
{

    int n,m;
    cin>>n>>m;

    if(abs(m-n)%2==1)
        cout<<"Burenka"<<endl;
    else
        cout<<"Tonya"<<endl;

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
