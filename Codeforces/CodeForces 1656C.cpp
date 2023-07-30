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
const double eps=1e-10;


void solve(){
   int n;
   cin>>n;
   vector<int> v(n);
    bool found=false;
    for(auto& x: v){
        cin>>x;
        if(x==1)
            found=true;
    }

    sort(range(v));

    bool consec=false;
    for(int i=0;i+1<n;i++){
        if(v[i]+1==v[i+1]){
            consec=true;
            break;
        }
    }
    if(!found){
        cout<<"YES"<<endl;
    }else{
        if(consec){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
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
    
 


}

