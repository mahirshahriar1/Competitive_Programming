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

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(m);
    takeInput(v);
    if(k>m){
        cout<<"NO"<<endl;
        return;
    }

    sort(v.rbegin(),v.rend());
    bool ok=true;
    int extra=n%k;
    int need=n/k;
    
    for(int i=0;i<extra;i++){
        v[i]--;
    }
    for(int i=0;i<m;i++){
        if(v[i]>need){
            ok=false;
            break;
        }
    }

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
   

    return 0;
}
