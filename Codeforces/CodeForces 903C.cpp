#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    vector<ll> v;

    for(int i=0; i<t; i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    set<ll>s;
    int count =0;
    for(int i=0; i<t; i++)
    {
        for(int j=i+1; j<t; j++)
        {

            if(v[j]>v[i])
            {
                if(s.find(j)==s.end())
                {
                    s.insert(j);
                    count++;
                    break;
                }

            }
        }

    }
    cout<<t-count<<endl;


    return 0;
}
