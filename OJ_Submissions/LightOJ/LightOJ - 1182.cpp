#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;

ll countSetBits(ll n)
{   
    return (n == 0?0:1 + countSetBits(n & (n - 1))); 
}

int kas=0;       
void solve()
{          
    ll n; cin>>n;
    cout<<"Case "<<++kas<<": "<<(countSetBits(n)%2?"odd":"even")<<endl;
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
