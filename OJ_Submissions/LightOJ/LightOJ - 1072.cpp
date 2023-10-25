#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)


int kas=0;

void solve()
{       
    double R;
    int n;
    cin>>R>>n;
    double r=(R*sin(pi/n))/(1+sin(pi/n));
    cout<<fixed<<setprecision(10)<<"Case "<<++kas<<": "<<r<<endl;
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
 
