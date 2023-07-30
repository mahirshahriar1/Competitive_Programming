#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    ll n, val=998244353;
    cin>>n;

    if(abs(n)%val==0)
        cout<<0<<endl;
    else if(n>=val)
    {
        ll temp=n/val;

        val*=temp;
        cout<<abs(n)-val<<endl;
    }

    else if(n<val&&n>0)
        cout<<n<<endl;
    else if(n<0&&abs(n)<=val)
    {
        cout<<val-abs(n)<<endl;
    }
    else
    {
        ll temp=-n/val;
        temp++;
        val*=temp;
        cout<<val-abs(n)<<endl;
    }

    return 0;
}
