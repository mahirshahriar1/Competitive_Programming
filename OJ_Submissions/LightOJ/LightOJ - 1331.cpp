#include <bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long int ll;
using namespace std;
const double eps=1e-9;


int kas=0;       
void solve()
{            
    double r1,r2,r3;
    cin>>r1>>r2>>r3;

    double s=(r1+r3+r1+r2+r2+r3)/2;
    double T_area=sqrt(s*(s-r1-r3)*(s-r2-r1)*(s-r3-r2));
    //cout<<T_area<<endl;
    double angle_r1=acos((pow(r1+r2,2)+pow(r1+r3,2)-pow(r2+r3,2))/(2*(r1+r2)*(r1+r3)));
    double angle_r2=acos((pow(r1+r2,2)+pow(r3+r2,2)-pow(r1+r3,2))/(2*(r1+r2)*(r3+r2)));
    double angle_r3=acos((pow(r1+r3,2)+pow(r3+r2,2)-pow(r2+r1,2))/(2*(r3+r2)*(r3+r1)));
    //cout<<angle_r1<<' '<<angle_r2<<' '<<angle_r3<<endl;
    double r1_area=.5*r1*r1*angle_r1;
    double r2_area=.5*r2*r2*angle_r2;
    double r3_area=.5*r3*r3*angle_r3;
    //cout<<r1_area<<endl;
    double ans=T_area-r1_area-r2_area-r3_area;
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



}
