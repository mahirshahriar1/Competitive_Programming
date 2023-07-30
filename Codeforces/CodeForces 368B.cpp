#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)


int main()
{
    fastio;
    int n,m,l;

    set<int>s;
    cin>>n>>m;

    vector <int> arr(n+5),ans(n+5);
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
    }
    for(int i=n;i>=1;i--)
    {
        s.insert(arr[i]);
        ans[i]=s.size();
    }
    for(int i=0;i<m;i++)
    {
        cin>>l;
        cout<<ans[l]<<endl;
    }
    return 0;
}
