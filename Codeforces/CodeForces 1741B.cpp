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
     
     if(n==3){
          cout<<-1<<endl;
          return;
     }else if(n==5){
          cout<<"5 4 1 2 3"<<endl;
          return;
     }
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      arr[i]=i+1;
    }
    sort(arr.rbegin(),arr.rend());   

     for(int i=0;i<n;i++){
          if(arr[i]==i+1){
               swap(arr[i],arr[i+1]);
          }
     }      
     
     print(arr);

}
void solve2(){
    int n;
    cin>>n;
    if(n==3){
        cout<<-1<<endl;
        return;
    }
    if(n%2==0){
        for(int i=n;i>0;i--){
            cout<<i<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=n/2+1;i<=n;i++){
        cout<<i<<' ';
    }
    for(int i=n/2;i>0;i--){
        cout<<i<<' ';
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
