#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)
const double eps=1e-9;
#define mod 10000007

int kas=0;

void solve()
{
    ll v[10010];

    for(int i=0;i<6;i++)        
    {
        cin>>v[i];
        v[i]=v[i]%mod;
    }
    ll n;
    cin>>n;
 
    for(int i=6;i<=n;i++)
        v[i]=(v[i-1]+v[i-2]+v[i-3]+v[i-4]+v[i-5]+v[i-6])%mod;
    
    cout<<"Case "<<++kas<<": "<<v[n]<<endl;    


}

int main()
{
    fastio;
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

    return 0;
}
