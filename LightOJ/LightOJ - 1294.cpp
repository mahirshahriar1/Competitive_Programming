#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

int kas=0;
void solve()
{
    ll a,b;
    cin>>a>>b;
    cout<<"Case "<<++kas<<": "<<a/2*b<<endl;
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
    


}
