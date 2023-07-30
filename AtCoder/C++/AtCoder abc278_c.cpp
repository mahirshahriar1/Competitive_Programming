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



int main(){

    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n,q;
   map<pair<int,int>,int> mp;
   cin>>n>>q;
   
   while(q--){
    int t,a,b;
    cin>>t>>a>>b;

    if(t==1){
        mp[{a,b}]++;
    }else if(t==2){
        if(mp.find({a,b})!=mp.end()){
            mp.erase({a,b});
        }
    }else{
        if(mp.find({a,b})!=mp.end() and mp.find({b,a})!=mp.end()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }


   }


    return 0;

}
