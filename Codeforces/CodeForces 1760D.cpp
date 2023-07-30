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

    vector<pair<int,int>> ans;
    int l,r;
    for(int i=0;i<n;i++){
        l=i,r=0;
        for(int j=i;j<n;j++){
            if(v[j]!=v[j+1]){
                r=j;
                i=j;
                break;
            }              
            r=j;
            i=j;
           
        }
        if(l==0){
            if(r==n-1){
                ans.push_back({l,r});
            }else if(v[r]<v[r+1]){
                ans.push_back({l,r});
            }
        }else if(v[l-1]>v[l]){      
                if(r==n-1)
                     ans.push_back({l,r});
                else if(v[r]<v[r+1])
                   ans.push_back({l,r});            
        }
    }
    int cnt=0;
    for(auto x:ans){
       // cout<<x.first<<' '<<x.second<<endl;
        cnt++;
    }
    if(cnt==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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
