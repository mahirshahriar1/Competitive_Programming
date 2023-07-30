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

    
    ll n,cs=0;
    while(cin>>n,n!=0){
        cout<<"Case "<<++cs<<":"<<endl;
        vector<ll> v(n);
        takeInput(v);
         
        vector<ll> sum;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                sum.push_back(v[i]+v[j]);
            }
        }
        sort(range(sum));
       // prll(sum)
        ll m;
        cin>>m;
        while(m--){
            ll a;
            cin>>a;
            auto itr=lower_bound(range(sum),a);
            if(itr==sum.end())
                itr--;

            cout<<"Closest sum to "<<a<<" is ";
            ll temp=*itr;
            itr--;
            if(abs(a-temp)<=abs(*itr-a))
                cout<<temp<<"."<<endl;
            else
                cout<<*itr<<"."<<endl;            
        }        

    }

    return 0;
}
