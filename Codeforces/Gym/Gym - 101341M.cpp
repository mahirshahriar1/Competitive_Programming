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

int main(){
    fastio  
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> v(n);

    int ind=-1;
    ll sum(0);
    for(int i=0;i<n;i++){  
        cin>>v[i];
        if(v[i]==0 and ind==-1)
        {
            ind=i-1;            
        }
        sum+=(ll)v[i];
    }
    if(sum>=n){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<pair<int,int>> ans;
    bool flag=false;
    int last=n-1;
    for(int i=ind;i>=0;i--){
        while(v[i]--){  
            ans.push_back({i+1,last+1});
            //cout<<last+1<<' '<<v[i]<<endl;            
            last--;
        }       
    }
 
    cout<<"YES"<<endl;
    for(auto x: ans){
        cout<<x.first<<' '<<x.second<<endl;
    }  


    return 0;
    
}
