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

    ll a,b;

    while(t--)
    {
        cin>>a>>b;
        map<int, int> m;

        ll x;
        for(int i=0;i<a;i++)
        {
            cin>>x;
            m[x]++;
        }
        for(int i=0;i<b;i++)
        {
            cin>>x;
            m[x]--;
        }

        ll count=0;

        for(auto itr:m)
        {
            //cout<<itr.first<<" "<<itr.second<<endl;
          if(itr.second!=0)
            count+=abs(itr.second);
        }
        cout<<count<<endl;

    }



    return 0;
}



