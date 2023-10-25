#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1,t2; cin>>t1>>t2;

    vector<ll> v1,v2;

    ll x;
    for(int i=0;i<t1;i++)
    {
        cin>>x;
         v1.push_back(x);
    }
     for(int i=0;i<t2;i++)
    {
        cin>>x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());

    for(int i=0;i<t2;i++)
    {
        auto itr=upper_bound(v1.begin(), v1.end(), v2[i])-v1.begin();
        cout<<itr<<" ";
    }


    return 0;
}
