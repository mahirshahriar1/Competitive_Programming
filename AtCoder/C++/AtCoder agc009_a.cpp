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
  

}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
   
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    ll cnt=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=cnt;
        if((a[i]+(a[i]%b[i]))%b[i]!=0){
            ll x=a[i]/b[i];
            x++;
            cnt+=b[i]*x-a[i];
        }else{
            cnt+=a[i]%b[i];
        }
            
    }
    cout<<cnt<<endl;


    return 0;
}
