#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;


    while(t--)
    {
        ll n,w;
        cin>>n>>w;
        ll W=w;
        multiset<ll> s;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            s.insert(x);
        }


        ll h=1;
        while(!s.empty())
        {
            auto itr=s.upper_bound(w);

            if(itr==s.begin())
            {
                w=W;
                h++;
                continue;
            }
            w-=*(prev(itr));
             s.erase(prev(itr));
           //  cout<<w<<endl;

        }
        cout<<h<<endl;

    }

    return 0;
}
