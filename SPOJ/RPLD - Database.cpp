#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;  cin>>t;

    int count=1;
    while(t--)
    {
        ll n,r; cin>>n>>r;

        vector<pair<ll,ll>> v(r);

        for(int i=0;i<r;i++)
        {
            cin>>v[i].first>>v[i].second;
        }
        sort(v.begin(),v.end());

        int flag=0;
        for(int i=0;i<v.size()-1;i++)
        {

            if(v[i].second==v[i+1].second)
            {
                if(v[i].first==v[i+1].first)
                    flag=1;
            }
        }
        if(flag)
        {
            cout<<"Scenario #"<<count++<<": impossible"<<endl;
        }
        else
            cout<<"Scenario #"<<count++<<": possible"<<endl;


    }


    return 0;
}
