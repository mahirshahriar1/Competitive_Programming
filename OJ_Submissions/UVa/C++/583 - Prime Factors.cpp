#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector <ll> pfactors(ll n)
{
    vector<ll> result;
    for(ll p=2; p*p<=n; p++)
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
    ll in;
    while(cin>>in, in!=0)
    {
        vector<ll> res=pfactors(abs(in));
        bool flag=true;
        cout<<in<<" = ";
        if(in<0) cout<<"-1 x ";  // negative print

        for (auto i=res.begin(); i!=res.end(); ++i)
        {
            if(i==prev((res.end())))
                cout<<*i<<endl;  // if last element then no x print
            else
                cout<<*i<<" x ";

            flag=false;
        }
        if(flag)
            cout<<endl;  // if doesn't go into the loop then new line print

    }


}
