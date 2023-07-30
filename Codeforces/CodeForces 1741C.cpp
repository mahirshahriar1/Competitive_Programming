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
    int n;
    cin>>n;
    vector<int> v(n);
    takeInput(v);
    int j,ans=INT_MAX;
    for(int i=1;i<=n;i++){
        int sum=accumulate(v.begin(),v.begin()+i,0); 

        int mn=i,cnt=0,temp=0;
        for(j=i;j<n;j++){          
            temp+=v[j];
            cnt++;
            if(temp==sum){                
                mn=max(mn,cnt);
                temp=0;
                cnt=0;
            }else if(temp>sum){
                break;
            }
        }

        if(j==n&&temp==0){            
            ans=min(ans,mn);
        }
    }
    if(ans==INT_MAX) cout<<n<<endl;
    else cout<<ans<<endl;
    
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
