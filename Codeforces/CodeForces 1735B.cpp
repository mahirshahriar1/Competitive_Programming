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
    if(n==1){
        int temp; cin>>temp;
        cout<<0<<endl;
        return;
    }

    int arr[n];
    takeInput(arr);

    int mn=arr[0];
    int cnt=0;

    for(auto x:arr){  
        cnt+=x/(2*mn-1);
        if(x%(2*mn-1)==0)
            cnt--;        
    }
  
    cout<<cnt<<endl;
    
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
