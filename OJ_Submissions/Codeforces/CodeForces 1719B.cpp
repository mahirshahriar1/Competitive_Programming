#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define pi acos(-1)
#define mod 1000000007

#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve(){

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    bool found=true;
    for(int i=1;i<=n;i+=2){
        int a=i,b=i+1;
        if(((a+k)*b)%4==0){
            v.push_back({a,b});
        }else{
            swap(a,b);
            if(((a+k)*b)%4==0)
                v.push_back({a,b});
            else{
                found=false;
                break;
            }        
        }
    }
    if(found){
        cout<<"YES"<<endl;
        for(auto x: v){
            cout<<x.first<<' '<<x.second<<endl;
        }

    }else{
        cout<<"NO"<<endl;
    }


}

int main()
{
    fastio;
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
