#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);

const double eps=1e-9;

int kas=0;

void solve()
{
    double n;
    cin>>n;

    double sq_area=(4*n*n);
    double cir_area=2*acos(0)*n*n;


    cout<<fixed<<setprecision(2)<<"Case "<<++kas<<": "<<(sq_area-cir_area)+eps<<endl;


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
