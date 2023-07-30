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
    vector<int> v(n);
    takeInput(v)
    vector<ll> sum1(n+1,0);
    
    for(int i=0;i<n;i++){
       if(v[i]==0){
        sum1[i+1]=1;
       }
    }
    for(int i=1;i<=n;i++) sum1[i]+=sum1[i-1];

    ll cnt1=0;
    for(int i=0;i<n;i++){
       if(v[i]==1){
        cnt1+=sum1[n]-sum1[i];
       }
    }
  



    vector<ll> sum2(n+1,0);
    vector<int> v2=v;
    for(int i=0;i<n;i++){
        if(v2[i]==0){
            v2[i]=1-v[i];
            break;
        }
    }
    for(int i=0;i<n;i++){
       if(v2[i]==0){
        sum2[i+1]=1;
       }
    }
    for(int i=1;i<=n;i++) sum2[i]+=sum2[i-1];

    ll cnt2=0;
    for(int i=0;i<n;i++){
       if(v2[i]==1){
        cnt2+=sum2[n]-sum2[i];
       }
    }


    vector<int> v3=v;
    vector<ll> sum3(n+1,0);

    for(int i=n-1;i>=0;i--){
       if(v3[i]==1){
        v3[i]=1-v3[i]; break;
       }
    }  
    for(int i=0;i<n;i++){
       if(v3[i]==0){
        sum3[i+1]=1;
       }
    }
    for(int i=1;i<=n;i++) sum3[i]+=sum3[i-1];

    ll cnt3=0;
    for(int i=0;i<n;i++){
       if(v3[i]==1){
        cnt3+=sum3[n]-sum3[i];
       }
    }


    cout<<max(cnt1,max(cnt2,cnt3))<<endl;
   
   
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
