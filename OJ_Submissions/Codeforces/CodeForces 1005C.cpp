#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,cnt=0;
    vector <ll> v;
    v.push_back(1); //2^0
    for(n =2;n<=1e9;n=n*2)
        v.push_back(n);
    v.push_back(n);

    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n);
    int size=v.size();

    for(ll i=0;i<n;i++)
    {
        bool found=false;
        for(ll j=0;j<v.size();j++)
        {
            if(v[j]<=arr[i])
                continue;
            ll val=v[j]-arr[i];

            auto itr=lower_bound(arr, arr+n,val);

            if(*itr==val)
            {
                if(itr-arr==i)
                {
                    itr++;
                    if(itr!=arr+n&&*itr==val)
                    {
                        found=true;
                        break;
                    }

                }
                else
                {
                    found=true;
                    break;
                }
            }

        }
        if(!found)
            cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}

