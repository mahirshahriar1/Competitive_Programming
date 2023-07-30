#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

int diff(int &a, int &b){
    return abs(a-b);
}

void solve(){
    int l,r,x,a,b;
    cin>>l>>r>>x>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }  
    if(abs(a-b)>=x){
      cout<<1<<endl;
      return;
    }
    
    if(b>a){
        if(b+x<=r || a-x>=l){
            cout<<2<<endl;
        }else if(a+x<=r and (b-l)>=x){
            cout<<3<<endl;
        }else{
            cout<<-1<<endl;
        }
    }else{
        if(b-x>=l || a+x<=r){
            cout<<2<<endl;
        }else if(a-x>=l and (r-b)>=x){
            cout<<3<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    
}

int main(){
    fastio  
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
