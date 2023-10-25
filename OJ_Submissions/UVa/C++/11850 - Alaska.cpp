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


vector<int> v;

int dp[210][100];


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    while(cin>>n, n!=0){
        vector<int> v(n);
        takeInput(v);
        sort(range(v));
        
        bool ok=v[0]==0;
        vector<int> ans;
        for(int i=1;i<n;i++){
            ans.push_back(v[i]-v[i-1]);
        }
        
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>200){
                ok=false;
                break;
            }
        }
      
        if(ok and abs(v[n-1]-1422)>100){
            ok=false;            
        }

        cout<<(ok?"POSSIBLE\n":"IMPOSSIBLE\n");
        
    }

    return 0;
}
