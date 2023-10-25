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
    int sz;
    cin>>sz;
    string s;
    cin>>s;

    map<char,vector<int>>mp;
    for(int i=0;i<sz;i++){
        mp[s[i]].push_back(i+1);
    }

    int n;
    cin>>n;
    while(n--){
        string a;        
        cin>>a;
        int ans=-1;
        map<char,int> ch;
        for(int i=0;i<a.size();i++){
            char c=a[i];            
            ans=max(ans,mp[c][ch[c]]);
            ch[c]++;
        }        
        cout<<ans<<endl;
    }
    
}

int main(){
     
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif


    solve();
    
        
}
