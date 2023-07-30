#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<2<<endl;
    }
    else if(n%3==0)
    {
        cout<<n/3<<endl;
    }
    else
    {
        cout<<(n/3)+1<<endl;
    }

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





