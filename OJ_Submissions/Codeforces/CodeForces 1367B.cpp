#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps = 1e-9;


void solve()
{
    int n,cnt1=0,cnt2=0;
    cin>>n;

    int arr[n+1];
    for(int i=0; i<n; i++)
    {
         cin>>arr[i];
         if(i%2!=arr[i]%2)
         {
             if(arr[i]%2)
                cnt1++;
             else cnt2++;
         }

    }
    if(cnt1!=cnt2)
        cout<<-1<<endl;
    else
        cout<<cnt1<<endl;
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

