#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q,x,y;

    cin>>q;

    set <ll> s;

    while(q--)
    {
        cin>>y>>x;
        if(y==1)
            s.insert(x);
        else if(y==2)
            s.erase(x);
        else
        {
            if(s.find(x)!=s.end())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }

    return 0;
}
