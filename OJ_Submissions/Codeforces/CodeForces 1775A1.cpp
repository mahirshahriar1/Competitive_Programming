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

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size()-1;j++){
            string a=s.substr(0,i+1);
            string b=s.substr(i+1,j-i);
            string c=s.substr(j+1);
            if(a<=b && c<=b || b<=a && b<=c){
                cout<<a<<' '<<b<<' '<<c<<endl;
                return;
            }
        }
    }

    cout<<":("<<endl;

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
