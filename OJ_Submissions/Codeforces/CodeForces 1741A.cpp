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
     string a,b;
     cin>>a>>b;

     if(a[a.size()-1]>b[b.size()-1]){
          cout<<"<"<<endl;
          return;
     }else if(a[a.size()-1]<b[b.size()-1]){
           cout<<">"<<endl;
           return;
     }

     if(a[a.size()-1]==b[b.size()-1]){
          if(a[a.size()-1]=='S')
          {
               if(a.size()>b.size()){
                    cout<<"<"<<endl;
                    return;
               }else if(a.size()<b.size()){
                    cout<<">"<<endl;
                    return;
               }else{
                    cout<<"="<<endl;
                    return;
               }
          }else if(a[a.size()-1]=='L'){               
               if(a.size()<b.size()){
                    cout<<"<"<<endl;
                    return;
               }else if(a.size()>b.size()){
                    cout<<">"<<endl;
                    return;
               }else{
                    cout<<"="<<endl;
                    return;
               }          
          }else {
               cout<<"="<<endl;
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
