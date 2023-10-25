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

ll binExpRecur(ll a, ll b)  //power
{
    if(b==0) return 1;
    ll res= binExpRecur(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}


int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    ll n;
    cin>>n;
    
    const ll arr[]={0,9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};

    ll ans=0;
    for(int i=1;i<=10;i++){
        if(n-arr[i]>=0){
            ans+=i*arr[i];
            n-=arr[i];
        }
        else{
            ans+=i*n;
            break;
        }
    }
    cout<<ans<<endl; 

    
    return 0;
}
