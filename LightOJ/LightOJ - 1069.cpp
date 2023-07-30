#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int kas=0;

void solve()
{
    int a,b;
    cin>>a>>b;

    int val1=abs(b-a)*4+3+5+3;
    int val2=abs(a)*4+3+5;

    cout<<"Case "<<++kas<<": "<<val1+val2<<endl;


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
    while(t--){
        solve();
    }


}
