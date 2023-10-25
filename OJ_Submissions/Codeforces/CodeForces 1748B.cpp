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

    ll ans=0;

    for(int i=0;i<n;i++){
        vector<int> freq(10,0);  
        set<int> st;
        // int dis=0;  
        int mx=0;
        for(int j=0; j<100 && i+j<n; j++){
            int num=s[i+j]-'0';   
            
             //if(freq[num]==1) dis++;
            st.insert(num);
            
            freq[num]++;
            mx=max(mx,freq[num]);
            
            //if(dis>=mx){
            if(st.size()>=mx){
                ans++;
            }
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

    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
