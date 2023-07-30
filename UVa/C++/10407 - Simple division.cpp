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

ll GCD(ll a, ll b)
{
        if(b==0)
            return a;
        return GCD(b,a%b);
} 

int main()
{
    fastio;
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w",stdout);
    #endif  
     
    vector<int>v;
    while(1)
    {
        ll x;
        cin>>x; 
        if(x==0)  break;
          v.push_back(x);
          
        while(cin>>x,x!=0)
          v.push_back(x);

        ll ans=0;

        for(ll i=1;i<v.size();i++)
            ans=GCD(ans,v[i]-v[i-1]);       

        v.clear();
        cout<<abs(ans)<<endl;
    
    }
    
    
    return 0;
}
