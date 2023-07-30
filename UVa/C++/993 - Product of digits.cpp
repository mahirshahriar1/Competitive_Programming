#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


vector <ll> pfactors(ll n)
{
    vector<ll> result;

    for(ll p=9; p>1; p--) //single digit factors only so from 9. 
    {
        while(n%p==0)
        {
            n/=p;
            result.push_back(p);
        }
    }
    if(n>1)
        result.push_back(n);

    return result;
}

int main()
{

    fastio;

    ll t;
    cin>>t;
    while(t--)
    {
        ll in;
        cin>>in;
          if(in>=0&&in<=9)
          {
              cout<<in<<endl;
              continue;
          }

        vector <ll> v=pfactors(in);
        sort(v.begin(),v.end());

        if(v[v.size()-1]>9)
        {
            cout<<-1<<endl;
            continue;
        }

        for(auto x: v)
        {
            cout<<x;
        }

        cout<<endl;

    }


}
