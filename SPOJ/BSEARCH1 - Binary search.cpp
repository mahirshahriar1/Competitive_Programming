#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

vector<ll> v;

ll binarysearch(ll key)
{
    ll l=0, r=v.size()-1;
    ll res=-1;
    while(l<=r){
        ll mid = (l + r) / 2;
        if (v[mid] == key){
            res=mid;
            r=mid-1;
        }else if(v[mid]>key){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return res;
}


int main()
{
    fastio;

    ll n,t;
    cin>>n>>t;
    while(n--)
    {
        ll temp;cin>>temp;
        v.push_back(temp);
    }
    while(t--)
    {
        ll temp; cin>>temp;
        cout<<binarysearch(temp)<<endl;
    }


    return 0;
}
