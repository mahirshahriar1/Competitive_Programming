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

struct point{
    int val;
    int index;
};
bool comp(point a,point b){
    return a.val<b.val;
}
void solve(){
    int n;
    cin>>n;

    vector<point> v(n+1);
    v[0].val=0;
    v[0].index=0;
    
    for(int i=1;i<=n;i++){
        v[i].index=i; 
        v[i].val=0;   
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            int x;
            cin>>x;
            v[x].val+=j;
        }
    }
   sort(range(v),comp);
   for(auto x:v){
        if(x.index!=0)
         cout<<x.index<<" ";
   }
   cout<<endl;
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
