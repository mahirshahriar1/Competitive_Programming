#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353

using namespace std;

int main()
{
    ll t,n;

    cin>>t;
    vector <ll> arr;
    while(t--)
    {
        cin>>n;
        ll p=0,c=0;
        while(n)
        {
            ll x=(n%10)*pow(10,p++);

            if(x>0)
            {
                arr.push_back(x);
                c++;
            }

            n/=10;
        }
        cout<<c<<endl;
        for(auto x:arr)
            cout<<x<<" ";

        cout<<endl;
        arr.clear();

    }

    return 0;
}
