#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int odd=0, even=0;
    for(auto& x: v)
    {
        cin>>x;
        x%2?odd++:even++;
    }   
    cout<<((odd&&even)?"NO":"YES")<<endl;

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
