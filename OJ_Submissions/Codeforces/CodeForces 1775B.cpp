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

/* a≤b , c≤b || b≤a, and b≤c */

void solve(){
    string s;
    cin>>s;

    int ind=0;
    for(int i=1;i<s.size()-1;i++){
        if(s[i]=='a'){
            ind=i;
            break;
        }
    }
    if(ind>0){
        cout<<s.substr(0,ind)<<" a "<<s.substr(ind+1)<<endl;
    }else{
        cout<<s[0]<<' '<<s.substr(1,s.size()-2)<<' '<<s[s.size()-1]<<endl;
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
