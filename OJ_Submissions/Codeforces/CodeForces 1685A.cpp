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
     takeInput(v);
     sort(range(v));

     vector<int> ans(n);
     int j=0,x=0;
     for(int i=0;i<n/2;i++){
          ans[j++]=v[i];
          ans[j++]=v[(n/2)+(x)];
          x++;
     }
     for(int i=0;i<n;i++){
          if(i==0){
               if(ans[i]>ans[n-1]&&ans[i]>ans[i+1]){                    
                    continue;
               }else if(ans[i]<ans[n-1]&&ans[i]<ans[i+1]){
                    continue;
               }else{ 
                    cout<<"NO"<<endl;
                    return;
               }      
          }else if(i==n-1){           
               if(ans[i]>ans[0]&&ans[i]>ans[i-1]){
                    continue;
               }else if(ans[i]<ans[0]&&ans[i]<ans[i-1]){
                    continue;
               }else{
                    cout<<"NO"<<endl;
                    return;
               } 
          }else{
               if(ans[i]>ans[i+1]&&ans[i]>ans[i-1]){
                    continue;
               }else if(ans[i]<ans[i+1]&&ans[i]<ans[i-1]){
                    continue;
               }else{
                    cout<<"NO"<<endl;
                    return;
               } 
          }
          
     }
     cout<<"YES"<<endl;
     print(ans)
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
