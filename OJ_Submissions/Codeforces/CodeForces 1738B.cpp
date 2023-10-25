#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;


void solve(){
    int n,k;
    cin>>n>>k;

    vector<ll> sum(n+1,0), v(n+1,0);

    for(int i=n-k+1;i<=n;i++){
        cin>>sum[i];
    }
    if(k==1){
        cout<<"YES"<<endl;
        return;
    }
    
    for(int i=n;i>=n-k+2;i--){
        v[i]=(sum[i]-sum[i-1]);
    }

    if(!is_sorted(v.begin()+n-k+2, v.end()))
        {
            cout<<"NO"<<endl;
            return;
        }

    for(int i=n-k+1;i>1;i--){
        v[i]=v[i+1];
        sum[i-1]=sum[i]-v[i];
    }
    v[1]=sum[1];
     
     if(!is_sorted(v.begin()+1, v.end()))
        {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
    

}

int main()
{
    
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
