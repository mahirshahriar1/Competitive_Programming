#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

vector<ll> v;

ll shorter(ll key)
{
    ll l=0, r=v.size()-1;
    ll res=-1;
    while(l<=r){
        ll mid = (l + r) / 2;
        if (v[mid] >= key){
            r=mid-1;
        }else{
            res=v[mid];
            l=mid+1;
        }
    }

    return res;
}

ll taller(ll key)
{

    ll l=0, r=v.size()-1;
    ll res=-1;
    while(l<=r){
        ll mid = (l + r) / 2;
        if(v[mid]<=key){
            l=mid+1;
        }else{
            res=v[mid];
            r=mid-1;
        }
    }

    return res;
}



int main()
{
    fastio;

    ll t;
    cin>>t;

    for(ll i=0;i<t;i++)
    {
        ll temp; cin>>temp;
        v.push_back(temp);
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll temp;
        cin>>temp;

        ll ans1=shorter(temp);
        ll ans2=taller(temp);
        if(ans1!=-1)
            cout<<ans1<<" ";
        else
            cout<<"X"<<" ";
        if(ans2!=-1)
            cout<<ans2<<endl;
        else
            cout<<"X"<<endl;

    }


    return 0;
}
