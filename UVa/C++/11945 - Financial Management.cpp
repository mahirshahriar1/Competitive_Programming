#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;

const double eps=1e-9;
const int mod = 1e9 + 7;

int kas;
void solve(){
   vector<double> v(12);
   
   double sum=0;
   for(auto x:v){
        cin>>x;
        sum+=x;
   }
   cout<<++kas<<' ';
   sum=sum/12;
  if(sum>=1000){
    int rem=sum/1000;
    sum=sum-rem*1000;
    cout<<'$'<<rem<<',';
    cout<<setprecision(2)<<fixed<<setfill('0')<<setw(6)<<sum<<endl;
  }
    else{
        cout<<'$'<<setprecision(2)<<fixed<<sum<<endl;
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
