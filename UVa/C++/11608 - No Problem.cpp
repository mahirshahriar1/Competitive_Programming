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


int kas;

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    
    ll n;
    while(cin>>n, n>=0){

        vector<ll> ques(12);
        takeInput(ques);
        vector<ll> req(12);
        takeInput(req);       
      

        cout<<"Case "<<++kas<<":"<<endl;

        for(int i=0;i<12;i++){
           // cout<<req[i]<<' '<<n<<endl;
            if(req[i]>0){                
                if(n<req[i]){
                    cout<<"No problem. :(\n";                   
                }
                else {
                    cout<<"No problem! :D\n";
                    n-=req[i];
                }
            }
            else cout<<"No problem! :D\n";
            n+=ques[i];
           // cout<<n<<endl;
        }
        

    }

}
