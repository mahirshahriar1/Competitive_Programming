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


vector<int> sumvecs(vector<int>& v1,vector<int>& v2){
    vector<int> temp;
    for(int i=0;i<v1.size();i++){
        temp.push_back(v1[i]+v2[i]);
    }
    return temp;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n,d,r;

    while(cin>>n>>d>>r, n!=0){
        
        vector<int> mor(n); for(auto &x: mor)   cin>>x;
        vector<int> eve(n); for(auto &x: eve)   cin>>x;        
        sort(range(mor));
        sort(range(eve),greater<int>());
        
        int ans=0;
        vector<int> v=sumvecs(mor,eve);
        for(int i=0;i<n;i++){           
            if(v[i]>d) ans+=(v[i]-d)*r;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
