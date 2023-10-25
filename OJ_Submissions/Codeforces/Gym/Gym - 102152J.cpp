  #include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

void solve()
{
   int n,m;
   cin>>n>>m;

   map <int, int> mp[n+1];

    int ans=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           int temp;
           cin>>temp;
           mp[i][temp]++;

            if(mp[i-1][temp])
            {
                mp[i-1][temp]--;
                ans++;
            }

       }
   }
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
