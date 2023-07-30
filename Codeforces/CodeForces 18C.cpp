#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;


int main()
{
    ll n;
    while(cin>>n)
    {
        ll sum=0,sum2=0,cnt=0;
        ll arr[n];

        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        for(ll i=0;i<n-1;i++)
        {
            sum2+=arr[i];
            if(sum2==(sum-sum2)) 
                cnt++;
        }
        cout<<cnt<<endl;
    }


}

