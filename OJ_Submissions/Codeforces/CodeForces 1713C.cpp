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
 
    vector<int> res(n,0);

    int curr=n-1;
    while(curr>0){
        int base=0;
        while(base*base<curr){
            base++;
        } 
        //cout<<base<<' '<<curr<<endl;
        int start=base*base-curr;
        int end=curr;
        for(int i=start;i<=end;i++){
            res[i]=curr;
            curr--;
        }
    }
    print(res)
    
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

    

}
