#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps=1e-9;


int kas=0;       
void solve()
{            
    ll ox,oy,ax,ay,bx,by;
    cin>>ox>>oy>>ax>>ay>>bx>>by;

    double opp=sqrt(pow(by-ay,2)+pow(bx-ax,2))/2;   
    double hyp=sqrt(pow(oy-ay,2)+pow(ox-ax,2));   
    double angle=asin(opp/hyp)*2;  
    double ans=angle*hyp;
    cout<<fixed<<setprecision(5)<<"Case "<<++kas<<": "<<ans+eps<<endl;
    
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
