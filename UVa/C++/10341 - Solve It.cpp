#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    double p,q,r,s,t,u;
    double val;
    while(cin>>p>>q>>r>>s>>t>>u){
        double l=0,h=1;

        auto check=[&](double x){
            return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
        };
        
        while(h-l>=1e-9){
            double mid=l+(h-l)/2.0;
            val=check(mid);
            if(val>=0) l=mid;
            else h=mid;
        }
        
        if(abs(val)<=1e-4) cout<<fixed<<setprecision(4)<<(l+h)/2.0<<endl;
        else cout<<"No solution"<<endl;
       
    }
    return 0;
}
