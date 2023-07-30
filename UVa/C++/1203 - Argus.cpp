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


    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;

    while(true){
        string s;
        cin>>s;
        if(s=="#") break;

        ll a,b;
        cin>>a>>b;
        pq.push({b,{a,b}});        
    }

    int q;
    cin>>q;
    ll a=0,b=0,cnt=1;
    while(q--){      
        auto x=pq.top();
        pq.pop();
       
        cout<<x.second.first<<endl;     
        pq.push({x.first+x.second.second,{x.second.first,x.second.second}});
    }
  


    return 0;

}
