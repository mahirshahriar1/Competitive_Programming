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

vector<ll> ans(999999+10);
void compute(){
    for(ll i=1;i<=999999+9;i++){
        string s=to_string(i);
        if(count(range(s),'0')==s.length()-1){
            ans[i]=1+ans[i-1];
        }else{
            ans[i]=ans[i-1];
        }
    }
}

void solve1(){
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
}

void solve(){
    int n;
    cin>>n;

    int ans=0;

    for(int i=1;i<=9;i++){
        int j=i;
        while(j<=n){
            ans++;
            //cout<<j<<endl;
            j*=10;
        }
    }
    cout<<ans<<endl;

}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    //compute();
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
