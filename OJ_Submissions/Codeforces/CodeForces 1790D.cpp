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


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int>mp;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
        s.insert(v[i]);
    }
    
    int k=0;

    for(auto x : s){
        while(mp[x]){
            k++;
            int val=x;
            mp[val]--;
            while(mp[val+1]){
                mp[val+1]--;
                val++;
            }        
        }
    }
    cout<<k<<endl;
    

   
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
