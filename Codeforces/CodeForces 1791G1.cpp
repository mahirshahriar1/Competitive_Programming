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

struct ind{
    ll val;
    ll index;
    ll cost;
};
bool comp(ind a,ind b){
    if(a.cost==b.cost)
        return a.index<b.index;
    return a.cost<b.cost;
}


void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ind>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].val;
        v[i].index=i+1;
        v[i].cost=i+1+v[i].val;
    }
    sort(range(v),comp);
   // for(auto x : v)        cout<<x.val<<' '<<x.index<<' '<<x.cost<<endl;
    ll i=0;
    while(q>0 and i<n){
        if(q-v[i].cost>=0 ){         
            q-=v[i].cost;    
            //cout<<v[i].index<<' '<<v[i].cost<<endl;     
            i++;
        }else{
            break;
        }
    }
    cout<<i<<endl;

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
