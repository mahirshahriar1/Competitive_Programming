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

vector<int> v;
void sieve(){
    int i=1,j=2;
    while(i<100)
    {
        v.push_back(i);
        i+=j++;
    }
}

void solve(){    
    int k,n;
    cin>>k>>n;

    int i=0;
    int cnt=k;
    int last=0;
    while(cnt--){
        cout<<v[i]<<' ';     
        last=v[i];   
        if(v[i+1]+cnt-1>n){                         
            break;
        }
        i++;
    }
    while(cnt>0){
        cout<<++last<<' ';
        cnt--;
    }
    cout<<endl;
}

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    sieve();
    //print(v);
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }

    return 0;
}
