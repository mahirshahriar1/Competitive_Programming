#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;


void solve()
{
    int n,x,y;
    cin>>n>>x>>y;

    if(!x&&!y||x&&y)
        {
            cout<<-1<<endl;
            return;
        }
    x=max(x,y);

    if((n-1)%x)
    {
        cout<<-1<<endl;
        return;
    }

    int player=1;
    bool flag=false;
    for(int i=1;i<n;i+=x)
    {
        for(int j=0;j<x;j++)
            cout<<player<<' ';
        if(!flag)
            player+=x+1, flag=true;
        else
            player+=x;
    }
    cout<<endl;
        

}

int main()
{
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
