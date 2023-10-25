#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;
#define range(v) v.begin(),v.end()
typedef long long int ll;
const double eps=1e-9;


void solve(int n){
    vector<int> v(n);
    for(auto &x:v) cin>>x;

    sort(range(v));

    int val;
    cin>>val;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){

        auto itr=lower_bound(range(v),val-v[i]);
        if(itr!=v.end() and *itr==val-v[i]){
            ans.push_back({v[i],*itr});
        }
    }
    int mn=INT_MAX;
    pair<int,int> res;
    for(auto x: ans){
        if(abs(x.first-x.second)<mn){
            mn=abs(x.first-x.second);
            res=x;
        }
    }
    if(res.first>res.second) swap(res.first,res.second);
    cout<<"Peter should buy books whose prices are ";
    cout<<res.first<<" and "<<res.second<<"."<<endl;
    cout<<endl;

        
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    while(cin>>n){
        solve(n);
    }

    return 0;

}
