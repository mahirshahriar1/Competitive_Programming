#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps=1e-9;


int kas=0;       
void solve()
{            
    double v1,v2,v3,a1,a2;
    cin>>v1>>v2>>v3>>a1>>a2;
    double d=(pow(v1,2)/(2*a1))+(pow(v2,2)/(2*a2));
    double bird1=(v1/a1)*v3;
    double bird2=(v2/a2)*v3;

    cout<<fixed<<setprecision(10)<<"Case "<<++kas<<": "<<d<<' '<<max(bird1,bird2)<<endl;  
    
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
