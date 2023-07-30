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
    ll p;
    while(cin>>p){
        ll i=1;
        ll n=1;
        while(n<p)
        {
            if(i%2==0)
                n*=2;
            else
                n*=9;
            i++;
        }
        if(i&1){
            cout<<"Ollie wins."<<endl;
        }
        else{
            cout<<"Stan wins."<<endl;
        }
    }
}
