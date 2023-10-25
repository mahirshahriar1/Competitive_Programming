#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi 2*acos(0.0)

int kas=0;

void solve()
{       
    int r1,r2,p,h;
    // volm of conical frstum- pi/3* h *(r1^2+r2^2+(r1*r2))
    
    cin>>r1>>r2>>h>>p;
    
    double r3=(p*(r1-r2)/(double)h)+r2;
    
    double ans=pi/3 * p * (pow(r2,2)+pow(r3,2)+(r2*r3));
    
    cout<<fixed<<setprecision(10)<<"Case "<<++kas<<": "<<ans<<endl;    
    
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
   
    return 0;
}
 
