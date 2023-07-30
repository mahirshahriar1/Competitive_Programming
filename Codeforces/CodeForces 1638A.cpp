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
    int arr[n];
    takeInput(arr);
    int ind=-1;
    for(int i=0;i<n;i++){
        if(ind!=-1)
            {
                cout<<arr[i]<<' ';
                continue;
            }
        if(arr[i]==i+1)
            cout<<arr[i]<<' ';
        else{           
            for(int j=i;j<n;j++){
                if(i+1==arr[j]){
                    ind=j;
                    break;
                }
            }
            for(int j=ind;j>=i;j--){
                cout<<arr[j]<<' ';
            }
            i=ind;
        }      
    }
    cout<<endl;

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
