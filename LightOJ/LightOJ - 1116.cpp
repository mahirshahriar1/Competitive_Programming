#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps=1e-9;


int kas=0;       
void solve()
{            
    ll n;
    cin>>n;
    if(n%2)
     cout<<"Case "<<++kas<<": Impossible"<<endl;  
    else
    {
        ll temp=n;
        ll a,b;
        while(n%2==0)
        {
            a=n/2;
            n/=2;
        }
        b=temp/a;
         cout<<"Case "<<++kas<<": "<<a<<' '<<b<<endl;  
    }
    
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
    cin.ignore();
    while(t--)
    {
        solve();
    }  



}
