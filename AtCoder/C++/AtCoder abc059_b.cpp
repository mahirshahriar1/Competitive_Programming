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

}

int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    string a,b;
    cin>>a>>b;
    if(a.size()<b.size()){
        cout<<"LESS"<<endl;
    }else if(a.size()>b.size()){
        cout<<"GREATER"<<endl;
    }else{
        ll n=a.size();
        for(ll i=0;i<n;i++)
        {
            if(a[i]<b[i]){
                cout<<"LESS"<<endl;
                return 0;
            }else if(a[i]>b[i]){
                cout<<"GREATER"<<endl;
                return 0;
            }
        }
        cout<<"EQUAL"<<endl;
    }
        
        
}
