#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


void solve()
{
    ll n;
    cin>>n;

    vector<ll>arr1(n),arr2(n),ans(n);

    for(ll i=0;i<n;i++)
        cin>>arr1[i];

    for(ll i=0;i<n;i++)
    {
          cin>>arr2[i];
          ans[i]=arr2[i]-arr1[i];
    }

    sort(ans.rbegin(),ans.rend());

    ll cnt=0,i=0,j=ans.size()-1;
    while(i<j)
    {
        if(ans[i]+ans[j]>=0)
        {
            i++;
            j--;
            cnt++;
        }
        else{
            j--;
        }
    }
    cout<<cnt<<endl;


}

int main()
{
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}
