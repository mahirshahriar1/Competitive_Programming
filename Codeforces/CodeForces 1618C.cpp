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


void solve(){
   int n;
   cin>>n;
   vector<ll> v(n);
   takeInput(v)

   bool flag1=true,flag2=true;
   ll gcd1=v[0],gcd2=v[1];
   for(int i=0;i<n;i+=2){
        gcd1=__gcd(gcd1,v[i]);
   }
   for(int i=1;i<n;i+=2){
        gcd2=__gcd(gcd2,v[i]);
   }
   
   for(int i=1;i<n;i+=2){
        if(v[i]%gcd1==0){
            flag1=false;
            break;
        }
   }
   for(int i=0;i<n;i+=2){
       if(v[i]%gcd2==0){
            flag2=false;
            break;
        }
   }
   if(flag1){
    cout<<gcd1<<endl;
   }else if(flag2){
    cout<<gcd2<<endl;
   }else{
    cout<<0<<endl;
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
