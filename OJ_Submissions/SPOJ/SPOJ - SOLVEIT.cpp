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


int main()
{    
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n,q;
    cin>>n>>q;
    vector<int> v(n+1,0);
    set<int> ind;
    while(q--){
        int y,k;
        cin>>y>>k;
        if(y==1){
            ind.insert(k);
        }else{
            auto itr=ind.lower_bound(k);
            if(itr==ind.end()){
                cout<<-1<<endl;
            }else{
                cout<<*itr<<endl;
            }
        }
    }
  
   

}
