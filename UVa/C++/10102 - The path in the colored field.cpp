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

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    while(cin>>n){
        vector<string> v(n);
        takeInput(v);
        vector<pair<int,int>> one,three;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='1') one.push_back({i,j});
                else if(v[i][j]=='3') three.push_back({i,j});
            }
        }
        int ans=0;
        for(auto x:one){
            int mn=INT_MAX;
            for(auto y:three){
                mn=min(mn,abs(x.first-y.first)+abs(x.second-y.second));
            }
            ans=max(ans,mn);
        }
        cout<<ans<<endl;
    }
}
