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
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<s.size();i++){
        if(!(s[i]=='Y' || s[i]=='e' || s[i]=='s')){
            cout<<"NO"<<endl;
            return;
        }
        if(s[i]=='s' and i+1 <n){
            if(s[i+1]!='Y'){
                cout<<"NO"<<endl;
                return;
            }
        }else if(s[i]=='Y' and i+2 <n){
            if(s[i+1]!='e'){
                cout<<"NO"<<endl;
                return;
            }
            if(s[i+2]!='s'){
                cout<<"NO"<<endl;
                return;
            }            
        }else if(s[i]=='Y' and i+1 <n){
            if(s[i+1]!='e'){
                cout<<"NO"<<endl;
                return;
            }
        }          
        else if(s[i]=='e' and i+1 <n){
            if(s[i+1]!='s'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;

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
