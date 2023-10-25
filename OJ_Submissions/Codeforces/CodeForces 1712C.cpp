#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define pi acos(-1)
#define mod 1000000007

#define takeInput(v) for(auto& x:v) cin>>x;
#define precision(n) fixed<<setprecision(n)
#define print(v) for(auto x:v) cout<<x<<' '; cout<<endl;

typedef long long int ll;
const double eps=1e-9;

void solve(){
    int n; 
    cin>>n;
    vector<int> arr(n);

    takeInput(arr);
    if(is_sorted(arr.begin(),arr.end()))
        {
            cout<<0<<endl;
            return;
        }

    vector<int> indices(n+1,-1);
    int cnt=0;
    for(int i=0;i<n;i++){     
        if(indices[arr[i]]==-1){
            indices[arr[i]]=i;
            cnt++;
        }
    }

    int ind=-1;    
    for(int i=n-1;i>=1;i--){
        if(arr[i]<arr[i-1]){
            ind=i-1;
            break;
        }
    }

    set<int> s;
    for(int i=n-1;i>=ind+1;i--){
        if(indices[arr[i]]>ind){
           s.insert(arr[i]);
        }else{
            break;
        }        
    }
        
    cout<<cnt-s.size()<<endl;  

}

int main(){
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
