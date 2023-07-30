#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <ll> v;
    map <ll,ll> m;

    ll x;

    while(cin>>x)
    {
        if(m[x]==0)
        {
            v.push_back(x);
             m[x]++;
        }
        else
            m[x]++;
    }
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" "<<m[v[i]]<<endl;


    return 0;
}
