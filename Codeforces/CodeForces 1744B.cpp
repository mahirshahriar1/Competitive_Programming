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

    int even(0),odd(0);
     ll sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp%2) odd++;
        else      even++;
        sum+=temp;        
    }
   // cout<<sum<<endl;
    while(q--){
        int a,num;
        cin>>a>>num;
        if(a==0){
            sum+=even*num;
            cout<<sum<<endl;
            if(num%2){
                odd+=even;
                even=0;              
            }            
        }else{           
            sum+=odd*num;
            cout<<sum<<endl;
            if(num%2){
                even+=odd;
                odd=0;
            }
        }
    }


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

    return 0;
}

