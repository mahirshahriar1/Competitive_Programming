#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;

void solve(){
    int n;
    cin>>n;
    vector <int> v(n);
    
    for(auto&x : v){
        cin>>x;
        x%2==0?x=0:x=1;
    }
   // print(v)
   
    int ans=0;
    
    int val=v[0];

    vector<vector<int> > vec;
    for(int i=0;i<n;i++){
        vector<int> temp;
        while(i<n and v[i]==val){
            //cout<<i<<' '<<v[i]<<endl;
            temp.push_back(v[i]);
            i++;
        }
        val=v[i];
        i--;
        vec.push_back(temp);
    }
    for(auto x: vec){        
        ans+=x.size()-1;           
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


