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

// bool comp(pair<ll,ll> a, pair<ll,ll> b){
//     return a.first<b.first;
// }

void solve(){
    ll n,k; 
    cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    multiset<ll> ms;
 
    for(int i=0;i<n;i++){
        cin>>v[i].first;        
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
        ms.insert(v[i].second);
    }

    ll i=0,attack=0;
    sort(v.begin(),v.end());
    while(i<n){
        if(k<=0){
            cout<<"NO"<<endl;
            return;
        }
        attack+=k;
        while(i<n and v[i].first<=attack){          
            auto itr=ms.find(v[i].second);
            ms.erase(itr);
            i++;
        }        
        if(!ms.empty()){           
            k-=*ms.begin();            
        }
    }
    cout<<"YES"<<endl;

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
