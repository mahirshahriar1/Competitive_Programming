#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q,t,y;
    string x;

    cin>>q;
    map <string,ll> data;

    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            data[x]+=y;
        }
        else if(t==2)
        {
            cin>>x;
            data.erase(x);
        }
        else
        {
            cin>>x;
            cout<<data[x]<<endl;
        }
    }


    return 0;
}
