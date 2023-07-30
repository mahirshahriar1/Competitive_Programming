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
    takeInput(v);
    sort(range(v));
    ll cnt=0;

    int comp=1;
    for(int i=0;i<n;i++){
        while(v[i]!=comp){
            v[i]--;
            cnt++;          
        }
        i=upper_bound(range(v),comp)-v.begin()-1;
        comp++;
    }    
    cout<<cnt<<endl;
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
