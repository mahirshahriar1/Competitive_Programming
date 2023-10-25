#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
 ll c=0;
    while(t--)
    {

        ll a,b;
        cin>>a>>b;

        set<ll> civi,spy;

        for(int i=0; i<b; i++)
        {
            ll x,y;
            cin>>x>>y;
            spy.insert(x);
            civi.insert(y);
        }

        int flag=1;
        for(int i=0; i<=a; i++)
        {
            if(spy.count(i)>0&&civi.count(i)>0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Scenario #"<<++c<<": spying"<<endl;
        else
            cout<<"Scenario #"<<++c<<": spied"<<endl;
    }


    return 0;
}
