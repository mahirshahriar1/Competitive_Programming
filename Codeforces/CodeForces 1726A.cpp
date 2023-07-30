#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

void solve()
{

    int n;
    cin>>n;
    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=1;i<n;i++)
       ans=max(ans,arr[i]-arr[0]);

    for(int i=0;i<n-1;i++)
       ans=max(ans,arr[n-1]-arr[i]);

    for(int i=1;i<n;i++)
       ans=max(ans,arr[i-1]-arr[i]);

    cout<<ans<<endl;

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
