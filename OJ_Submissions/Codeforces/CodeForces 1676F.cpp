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
    int n,k;
    cin>>n>>k;

    map <int,int> mp;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        mp[tmp]++;
    }
    
    vector<int> v;
    for(auto x: mp){
        if(x.second>=k){
            v.push_back(x.first);
        }
    }
    if(v.size()==0){
        cout<<-1<<endl;
        return;
    }
    mp.clear();

    sort(range(v));
    int l=v[0],r=v[0];
 
    bool flag=false;
    pair<int,int> b={0,0};
   
    for(int i=1;i<v.size();i++){        
        if(v[i]==v[i-1]+1){                   
            if(!flag) l=v[i-1];           
            r=v[i];            
            flag=true;
            continue;
        }
        else{           
            if(r-l>=b.second-b.first){
                b.second=r;
                b.first=l;
            }
            flag=false;
        }               
    }
    if(r-l>=b.second-b.first){
            b.second=r;
            b.first=l;
    }  

    cout<<b.first<<' '<<b.second<<endl;   
    
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
