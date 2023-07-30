#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define takeInput(v) for(auto& x:v) cin>>x;
#define range(v) v.begin(),v.end()
typedef long long int ll;


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll n,t;
    cin>>n>>t;

    vector<ll> v(n);
    takeInput(v);
    
    ll sum=accumulate(range(v),0LL);
    t-=t/sum*sum;

    for(ll i=0;i<n;i++){
        if(t<=v[i]){
            cout<<i+1<<' '<<t<<endl;
            break;
        }
        t-=v[i];
    }   

    return 0;
}
