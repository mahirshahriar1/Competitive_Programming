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

    if(s[0]!='9'){
        for(int i=0;i<n;i++){
            cout<<9-(s[i]-'0');
        }
        cout<<endl;
    }else{
        string ans;
        int carry=0;
        for(int i=n-1;i>=0;i--)
        {
            int num=(s[i]-'0')+carry;             
            if(num>1){
                int add=11-num;
                carry=1;
                ans+=(add+'0');
            }else{
                int add=1-num;
                carry=0;
                ans+=(add+'0');
            }
        }
        reverse(range(ans));
        cout<<ans<<endl;
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
