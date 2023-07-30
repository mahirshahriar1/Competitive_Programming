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


ll binexprecurmod(ll a, ll b, ll m){
    if(b==0) return 1;
    ll res = binexprecurmod(a,b/2,m);
    if(b%2==0) return (res*res)%m;
    else return (((res*res)%m)*a)%m;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    string arr[]={"76","16","56","96","36"};

    ll t;
    cin>>t;
    cin.ignore();
    while(t--){
        string n;
        cin>>n;
        if(n[0]=='0'){
            cout<<1<<endl;
        }else if(n[0]=='1' and n.size()==1){
            cout<<66<<endl;
        }else{           
            cout<<arr[(n[n.size()-1]-'0')%5]<<endl;
        }

    }
    return 0;

}
