#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

bool is_valid_triangle(ll a,ll b,ll c)
{
    ll arr[3]={a,b,c};
    sort(arr,arr+3);

    return arr[0]+arr[1]>arr[2];
}

int main()
{
    fastio;

    int t,kas=0;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll k=j;
                ll ind=upper_bound(v.begin(),v.end(), v[i]+v[j]-1)-v.begin();
                ind--; //as ub was taken so we decremented one index to get the index of (sum-1)
                if(ind!=j)
                    ans+=(ind-j); //gives us the number of valid triangle that can be formed
            }
        }


        cout<<"Case "<<++kas<<": "<<ans<<endl;
    }


    return 0;
}

/*
int main()
{
    fastio;

    int t,kas=0;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll k=j;
                ll ind=lower_bound(v.begin(),v.end(), v[i]+v[j])-v.begin();
                ind--;
                if(ind!=j)
                    ans+=(ind-j);
            }
        }


        cout<<"Case "<<++kas<<": "<<ans<<endl;
    }


    return 0;
}
*/
