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

// int flip(int x){
//     if(x==1) return -1;
//     else return 1;
// }

void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<int> p(n),a(m);
    map<int,int> mp;
    int hshs=1;
    for(auto &x: p){
        cin>>x;
        mp[x]=hshs++;
    }
    takeInput(a);
    
    bool flag=false;
    for(int i=0;i<m-1;i++){
        int val1=a[i];
        int val2=a[i+1];
        if(mp[val1]<mp[val2] and mp[val2]<=mp[val1]+d){
            continue;
        }
       
        flag=true;
        break;        
    }
    if(flag){
        cout<<0<<endl;
        return;
    }   
    int ans=INT_MAX;
    for(int i=0;i<m-1;i++){
        int val1=a[i];
        int val2=a[i+1];

        ans=min(ans,abs(mp[val2]-mp[val1]));  
                 
        int need=d+1-abs(mp[val2]-mp[val1]);
        int possible=mp[val1]-1+n-mp[val2];
        if(need<=possible){
            ans=min(ans,need);
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
