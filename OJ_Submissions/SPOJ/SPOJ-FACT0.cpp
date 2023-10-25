#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <pair<ll,ll>> pfactors(ll n)
{
    vector<pair<ll,ll>>result;
    for(ll p=2;p*p<=n;p++)
    {
        ll cnt=0;
        if(n%p)
            continue;
        while(n%p==0)
        {
            n/=p;
            ++cnt;
        }
         cout<<p<<"^"<<cnt<<" ";
    }
    if(n>1)
        cout<<n<<"^"<<1<<" ";
    return result;
}


int main()
{

    fastio;
    ll in;
    while(cin>>in, in!=0)
    {
       pfactors(in);
        cout<<endl;
    }


}
