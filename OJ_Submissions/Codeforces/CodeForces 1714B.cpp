#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    fastio;

    int t;cin>>t;
    while(t--)
    {
        int x;
        cin>>x;

        vector<ll> v;
        for(int i=0;i<x;i++)
        {
            ll in;
            cin>>in;
            v.push_back(in);
        }
        ll ans=0;
        bool flag=false;
        set <ll> s;
        reverse(v.begin(), v.end());

        for(int i=0;i<x;i++)
        {
            if(s.count(v[i])>0)
            {
                ans=i;
                flag=true;
                break;
            }
            else
                s.insert(v[i]);
        }
        if(flag)
            cout<<x-ans<<endl;
        else
            cout<<ans<<endl;
        s.clear();

    }

}
