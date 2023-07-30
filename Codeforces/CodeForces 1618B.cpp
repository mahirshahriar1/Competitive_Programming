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
   vector<string> v(n-2);
   takeInput(v)

//    if(n==3){
//     cout<<v[0];
//     cout<<v[0][0]<<endl;
//     return;
//    } 

   string ans;
   ans+=v[0][0];
   for(int i=0;i+1<n-2;i++){
        if(v[i][1]==v[i+1][0]){
            ans+=v[i][1];
        }else{
            ans+=v[i][1];
            ans+=v[i+1][0];
        }
   }
   ans+=v[n-3][1];
   cout<<ans;
   for(int i=ans.size();i<n;i++){
    cout<<v[0][0];
   }
   cout<<endl;

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
