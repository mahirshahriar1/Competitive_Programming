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


void solve2(){

     int n; cin>>n;
     vector<int> a(n),b(n);

     int a_cnt0=0,a_cnt1=0,b_cnt0=0,b_cnt1=0,diff=0;
     for(auto& x:a){
          cin>>x;
          if(x) a_cnt1++;
          else  a_cnt0++;
     }
     
     for(auto& x:b){
          cin>>x;
          if(x) b_cnt1++;
          else  b_cnt0++;
     }
     for(int i=0;i<n;i++){
          if(a[i]!=b[i])
               diff++;
     }
     if(a_cnt1==b_cnt1 and a_cnt0==b_cnt0){
          if(a==b) cout<<0<<endl;
          else     cout<<1<<endl;
          return;
     }
   
     cout<<min(diff,abs(a_cnt1-b_cnt1)+1)<<endl;

}


void solve(){
     int n;
     cin>>n;
     vector<int> a(n),b(n);
     int a_cnt1=0,a_cnt0=0,b_cnt1=0,b_cnt0=0;

     for(int i=0;i<n;i++){
          cin>>a[i];
          if(a[i]==0) a_cnt0++;
          else a_cnt1++;
     }
     
     for(int i=0;i<n;i++){
          cin>>b[i];
          if(b[i]==0) b_cnt0++;
          else b_cnt1++;
     }
     int mn=min(abs(a_cnt0-b_cnt0),abs(a_cnt1-b_cnt1));
     //cout<<mn<<endl;
     if(mn==abs(a_cnt1-b_cnt1)){
          if(a_cnt1>b_cnt1)
          {    
               for(int i=0;i<n;i++){
                    if(b[i]==0&&a[i]==1){
                         b[i]=1;
                         b_cnt1++;
                    }
                    if(b_cnt1==a_cnt1) break;
               }
          }else{
                for(int i=0;i<n;i++){
                    if(b[i]==1&&a[i]==0){
                         a[i]=1;
                         a_cnt0++;
                    }
                    if(b_cnt0==a_cnt0) break;
               }
          }
          
     }else{
          if(a_cnt1>b_cnt1)
          {    
               for(int i=0;i<n;i++){
                    if(b[i]==1&&a[i]==0){
                         b[i]=0;
                         b_cnt1++;
                    }
                    if(b_cnt1==a_cnt1) break;
               }
          }else{
                for(int i=0;i<n;i++){
                    if(b[i]==0&&a[i]==1){
                         a[i]=0;
                         b_cnt0++;
                    }
                    if(b_cnt0==a_cnt0) break;
               }
          }

     }
     if(a==b) cout<<mn<<endl;
     else cout<<mn+1<<endl;
     

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
