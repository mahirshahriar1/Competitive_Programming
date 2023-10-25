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
    string s;
    cin>>s;
    if(n==1){
        if(s=="W"){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        return;
    }else if(n==2){
        if(s=="BR"||s=="RB"||s=="WW"){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {        
        if(s[i]=='R'||s[i]=='B'){
            bool found=false;
            char c=s[i]=='R'?'B':'R';
            //cout<<i+1<<endl;
            for(int j=i+1;j<n;j++){
                if(s[j]==c){
                    found=true;
                }
                if(s[j]=='W') break;
                i=j;               
            }
          // cout<<i+1<<endl;
            if(!found){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
     
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

}
