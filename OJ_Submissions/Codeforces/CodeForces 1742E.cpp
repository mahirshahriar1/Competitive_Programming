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

void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> v(n),sum(n);   

    for(int i=0;i<n;i++){     
        cin>>v[i];       
        sum[i]=v[i];
        if(i){
            sum[i]+=sum[i-1];
        }          
    }

     for(int i=1;i<n;i++){ 
        v[i]=max(v[i],v[i-1]); 
     }    
     vector<ll> arr(q);
     takeInput(arr)
      
     for(int i=0;i<q;i++){
        auto itr=upper_bound(range(v),arr[i]);
        if(itr==v.begin()){
            cout<<0<<' ';
        }else{
            itr--;
            int ind=itr-v.begin();
            cout<<sum[ind]<<' ';
        }
     }
     cout<<endl;   
 
}

int main()
{
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
      //  cout<<__gcd(2,3)<<endl;

}

