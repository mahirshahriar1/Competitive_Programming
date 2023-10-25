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

vector<int> v;

bool possible(ll n,ll c, ll d, ll k){
    ll temp=0, coins=0, days=0;
    int i=0;
    while(true){
        if(i<n){
            coins+=v[i++];
        }
        if(coins>=c){
            return true;
        }  

        days++;
        if(days==d)
            return false;   

        temp++;
        if(temp==k+1){
            temp=0;
            i=0;
        }
        
    }
}

void solve(){
    ll n,c,d;
    cin>>n>>c>>d;
    v.clear();
    v.resize(n);
     takeInput(v);
    sort(range(v));
    reverse(range(v));

    ll l=0, r=2e18, k=-1;

    while(l<=r){
        ll mid=(l+r)>>1;
        
        if(possible(n,c,d,mid)){
            l=mid+1;
            k=mid;
        }else{
            r=mid-1;
        }
    }
    if(k==-1) cout<<"Impossible"<<endl;
    else if(k>d) cout<<"Infinity"<<endl;
    else     cout<<k<<endl;

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

}
