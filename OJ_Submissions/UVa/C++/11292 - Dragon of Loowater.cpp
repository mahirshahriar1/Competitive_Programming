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


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll n,m;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        vector<ll> head(n),knight(m);
        takeInput(head);
        takeInput(knight);
        sort(range(head));
        sort(range(knight));
        ll i=0,j=0;
        ll ans=0;
        while(i<n && j<m){
            if(knight[j]>=head[i]){
                ans+=knight[j];
                i++;
            }
            j++;
        }
        if(i==n) cout<<ans<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }

}
