#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

void solve(){
    int n,m,sx,sy,d;
    cin>>n>>m>>sx>>sy>>d;
  
    bool ans=true;
    if(sx-d<=1&&sy-d<=1)ans=false;
    if(sx+d>=n&&sy+d>=m)ans=false;
    if(sx+d>=n&&sx-d<=1)ans=false;
    if(sy+d>=m&&sy-d<=1)ans=false;
    
    if(ans)
        cout<<n+m-2<<endl;
    else
        cout<<-1<<endl;
}

int main()
{
    fastio
    #ifndef ONLINE_JUDGE
           freopen("input.txt", "r", stdin);
           freopen("output.txt", "w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

}

