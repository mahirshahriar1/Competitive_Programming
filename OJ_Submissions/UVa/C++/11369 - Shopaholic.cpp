#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
typedef long long int ll;


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(auto &x: v) cin>>x;

    sort(v.begin(), v.end());
    for(auto &x: v) cout<<x<<' ';
    ll ans=0;
    for(int i=n%3;i<n;i+=3){
        ans+=v[i];
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
