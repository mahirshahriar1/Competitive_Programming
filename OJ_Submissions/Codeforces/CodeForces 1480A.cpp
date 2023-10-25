#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve(){
    string t;
    cin>>t;
    string s=" ";
    s+=t;
    
    for(int i=1;i<s.size();i++){
        if(i%2){
            if(s[i]=='a'){
                cout<<'b';
            }else{
                cout<<'a';
            }
        }else{
            if(s[i]=='z'){
                cout<<'y';
            }else{
                cout<<'z';
            }

        }
    }
    cout<<endl;
}
int main()
{
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
