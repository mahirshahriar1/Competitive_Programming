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
#define pb push_back
typedef long long int ll;
const double eps=1e-9;


void solve(){
   int n;
   cin>>n;
   vector<pair<int,int>> v(n);
   for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
   }
   vector<pair<int,int>> arr=v;
   sort(v.rbegin(),v.rend());
   
   int j=0;
   int ind=INT_MAX,cnt=0;
  while(cnt!=n){
        while(true){
           if(v[j].second<ind){            
            ind=v[j].second;
            j++;
            break;
           }else{
               j++;
           }
        }
        //cout<<arr[ind].first<<endl;
        int x=cnt;
        for(int k=ind;k<n-x;k++){
            cnt++;
            cout<<arr[k].first<<' ';           
            
        }      
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
