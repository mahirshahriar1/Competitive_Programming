#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main ()
{
    ll n,s;
    ll x;
    cin>>n;
    vector <ll> arr;

    while(n--)
    {
        cin>>s;
        for(ll i=0; i<s; i++)
        {
            cin>>x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());

        ll ans;
        if(s==1)
             ans=arr[0]*arr[0];
        else
             ans=arr[0]*arr[s-1];

        deque<ll> divisors;


        for (ll i = 1; i * i <= ans; ++i)
        {
            if (ans % i == 0)
            {
                divisors.push_back(i);
                if (ans / i != i)
                {
                    divisors.push_back(ans / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        divisors.pop_front();
        divisors.pop_back();


        int flag=1;

        for(ll i=0;i<divisors.size();i++)
        {
            if(divisors[i]!=arr[i])
            {
                flag=0;
            }
        }

        if(flag)
            cout<<ans<<endl;
        else
            cout<<"-1"<<endl;

        arr.clear();
    }

    return 0;

}
